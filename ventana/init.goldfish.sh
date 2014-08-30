#!/system/bin/sh

#
# board-specific initialization requires some scripting intelligence not
# supported by Androids init system syntax. Therefore we run this script
# as a one-shot from Androids init-system at late_start.
#
# board-specific details handled here:
#  - DIO<n> gpio abstraction via gpio.dio<n> properties
#  - DIO<n> gpio sysfs permissions
#  - GPS UART device specification
#  - initial GPS configuration
#  - accelerometer orientation adjustment
#

# get board from cmdline
for x in `cat /proc/cmdline`; do
  [[ $x = androidboot.board=* ]] || continue
  board="${x#androidboot.board=}"
done

# as fallback get from eeprom manually
[ -z "$board" ] && {
	board=`dd if=/sys/devices/platform/imx-i2c.0/i2c-0/0-0050/eeprom \
		bs=1 count=16 skip=304 2>/dev/null | busybox hexdump -C | \
		busybox head -1 | busybox cut -c62-65`
}

pre="${0##*/}"
echo "$pre: Board: ${board}xx" > /dev/console

orientation=
cvbs_in=
hdmi_in=
case "$board" in
	GW54)
		orientation=0
		gps_device=/dev/ttymxc4
		# GPIO mappings
		setprop gpio.dio0 9
		setprop gpio.dio1 19
		setprop gpio.dio2 41
		setprop gpio.dio3 42
		# CANbus
		setprop gpio.can_stby 2
		# Video Capture
		hdmi_in=/dev/video0
		cvbs_in=/dev/video1
		;;
	GW53)
		orientation=3
		gps_device=/dev/ttymxc4
		# GPIO mappings
		setprop gpio.dio0 16
		setprop gpio.dio1 19
		setprop gpio.dio2 17
		setprop gpio.dio3 20
		# CANbus
		setprop gpio.can_stby 2
		# Video Capture
		cvbs_in=/dev/video0
		;;
	GW52)
		orientation=3
		gps_device=/dev/ttymxc4
		# GPIO mappings
		setprop gpio.dio0 16
		setprop gpio.dio1 19
		setprop gpio.dio2 17
		setprop gpio.dio3 20
		# CANbus
		setprop gpio.can_stby 9
		# Video Capture
		cvbs_in=/dev/video0
		;;
	GW51)
		gps_device=/dev/ttymxc0
		# GPIO mappings
		setprop gpio.dio0 16
		setprop gpio.dio1 19
		setprop gpio.dio2 17
		setprop gpio.dio3 20
		# Video Capture
		cvbs_in=/dev/video0
		;;
	*)
		echo "$pre: unknown board: $board" > /dev/console
		;;
esac

# Camera configuration
# (landscape mode orient is 0, For portrait mode orient is 90)
[ -r "${cvbs_in}" ] && {
	state="$(v4l2-ctl -d ${cvbs_in} --get-standard | busybox head -n1 | busybox awk '{print $4}')"
	case "$state" in
		0x000000ff) state="PAL";;
		0x0000b000) state="NTSC";;
		*) state=;;
	esac
	echo "$pre: cvbs_in:${cvbs} state=${state}" > /dev/console
	[ "$state" ] || cvbs_in=
	state_cvbs=$state
}
[ -r "${hdmi_in}" ] && {
	[ -d /sys/devices/platform/imx-i2c.2 ] && \
		dir=/sys/devices/platform/imx-i2c.2/i2c-2/2-0048/
	[ -d /sys/devices/soc0/soc.1/2100000.aips-bus/21a8000.i2c/ ] && \
		dir=/sys/devices/soc0/soc.1/2100000.aips-bus/21a8000.i2c/i2c-2/2-0048
	#state="$(cat $dir/state)"
	#echo "$pre: hdmi_in:${hdmi_in} state=${state}" > /dev/console
	[ "$state" = "locked" ] || hdmi_in=
	state_hdmi=$state
}
setprop camera.disable_zsl_mode 1
if [ "${cvbs_in}" -a "${hdmi_in}" ]; then
	echo "Front Camera: ${state_cvbs} Analog In"
	setprop front_camera_name adv7180_decoder
	setprop front_camera_orient 0
	echo "Front Camera: ${state_hdmi} HDMI In"
	setprop back_camera_name tda1997x_video
	setprop back_camera_orient 0
elif [ "${cvbs_in}" ]; then
	echo "Front Camera: ${state_cvbs} Analog In"
	setprop front_camera_name adv7180_decoder
	setprop front_camera_orient 0
	#setprop back_camera_name uvc
elif [ "${hdmi_in}" ]; then
	echo "Front Camera: ${state_hdmi} HDMI In"
	setprop front_camera_name tda1997x_video
	setprop front_camera_orient 0
	#setprop back_camera_name uvc
fi

# Accelerometer/Magnetometer physical orientation
[ "$orientation" -a -d /sys/bus/i2c/devices/2-001e ] && {
	i=0
	while [ 1 ]; do
		[ -d /sys/class/input/input${i} ] || break
		name="$(cat /sys/class/input/input${i}/name)"
		[ "$name" = "FreescaleAccelerometer" ] && {
			echo $orientation \
			  > /sys/devices/virtual/input/input${i}/position
			echo "$pre: Accelerometer input{$i} pos$orientation" \
			  > /dev/console
		}
		i=$((i+1))
	done
}

# GPS configuration
gps_present=1
[ $gps_present ] && {
	echo "$pre: GPS UART: $gps_device" > /dev/console
	ln -s $gps_device /dev/gpsdevice
	# set gps baudrate to 115200
	busybox stty -F /dev/gpsdevice 4800
	echo "\$PSRF100,1,115200,8,1,0*05" > /dev/gpsdevice
	busybox stty -F /dev/gpsdevice 115200
	# configure message reporting rate (third field is period in secs):
	echo "\$PSRF103,00,00,01,01*25" > /dev/gpsdevice # GGA
	echo "\$PSRF103,01,00,01,01*24" > /dev/gpsdevice # GLL
	echo "\$PSRF103,02,00,01,01*27" > /dev/gpsdevice # GSA
	echo "\$PSRF103,03,00,01,01*26" > /dev/gpsdevice # GSV
	echo "\$PSRF103,04,00,01,01*21" > /dev/gpsdevice # RMC
	echo "\$PSRF103,05,00,01,01*20" > /dev/gpsdevice # VTG
}

# export DIO's and configure them all as inputs
# but allow user 'system' to modify value and direction
i=0
while [ 1 ]; do
	gpio=$(getprop gpio.dio${i})
	[ "$gpio" ] || break
	echo "$pre: MX6_DIO$i gpio$gpio" > /dev/console

	# export
	echo ${gpio} > /sys/class/gpio/export
	# configure as output-low
	echo out > /sys/class/gpio/gpio${gpio}/direction
	echo 0 > /sys/class/gpio/gpio${gpio}/value
	# allow all users to modify value
	chown system.system /sys/class/gpio/gpio${gpio}/value
	chmod 0666 /sys/class/gpio/gpio${gpio}/value
	# allow all users to modify direction
	chown system.system /sys/class/gpio/gpio${gpio}/direction
	chmod 0666 /sys/class/gpio/gpio${gpio}/direction
	i=$((i+1))
done

# initialize CAN bus
gpio=$(getprop gpio.can_stby)
[ "$gpio" -a -d /sys/class/net/can0 ] && {
	echo "$pre: Configuring CANbus for 500kbps CAN_STBY=gpio$gpio" \
		> /dev/console
	ip link set can0 type can bitrate 500000 triple-sampling on
	ifconfig can0 up

	# export CAN_STBY gpio
	echo ${gpio} > /sys/class/gpio/export
	# configure as output-low (enable transceiver)
	echo out > /sys/class/gpio/gpio${gpio}/direction
	echo 0 > /sys/class/gpio/gpio${gpio}/value
	# allow all users to modify value
	chown system.system /sys/class/gpio/gpio${gpio}/value
	chmod 0666 /sys/class/gpio/gpio${gpio}/value
}
