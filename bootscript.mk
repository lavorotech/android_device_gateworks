BOOTSCRIPT_TARGET := $(PRODUCT_OUT)/boot/boot/6x_bootscript-ventana
$(BOOTSCRIPT_TARGET): device/flowdata/provue/6x_bootscript.txt $(PRODUCT_OUT)/u-boot.img
	mkdir -p $(dir $@)
	$(TOPDIR)bootable/bootloader/uboot-imx/tools/mkimage -A arm -O linux -T script -C none -a 0 -e 0 -n "boot script" -d $< $@

BOOTSCRIPT_TARGET_BAK := $(PRODUCT_OUT)/boot/boot/6x_bootscript-ventana.bak
$(BOOTSCRIPT_TARGET_BAK): device/flowdata/provue/6x_bootscript.txt $(PRODUCT_OUT)/u-boot.img
	mkdir -p $(dir $@)
	$(TOPDIR)bootable/bootloader/uboot-imx/tools/mkimage -A arm -O linux -T script -C none -a 0 -e 0 -n "boot script" -d $< $@

BOOTSCRIPT_TARGET_REC := $(PRODUCT_OUT)/boot/boot/6x_bootscript-ventana.recovery
$(BOOTSCRIPT_TARGET_REC): device/flowdata/provue/6x_bootscript_recovery.txt $(PRODUCT_OUT)/u-boot.img
	mkdir -p $(dir $@)
	$(TOPDIR)bootable/bootloader/uboot-imx/tools/mkimage -A arm -O linux -T script -C none -a 0 -e 0 -n "boot script" -d $< $@

.PHONY: bootscript
bootscript: $(BOOTSCRIPT_TARGET) $(TARGET_BOOTLOADER_IMAGE) $(BOOTSCRIPT_TARGET_BAK) $(BOOTSCRIPT_TARGET_REC)

droidcore: bootscript
