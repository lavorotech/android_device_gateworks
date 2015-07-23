unsigned short i2c_upgrader_address[2] = {0xE552, 0xFFFE};
unsigned char i2c_upgrader_data[2][1024] = {
	{
		0x31,0x40,0x00,0x04,0xB0,0x12,0x5E,0xE5,0xB0,0x12,0x84,0xE7,0xB2,0x40,0x80,0x5A,
		0x20,0x01,0xF2,0x40,0x0D,0x00,0x57,0x00,0xD2,0x42,0xFB,0x10,0x57,0x00,0xD2,0x42,
		0xFA,0x10,0x56,0x00,0xF2,0xC0,0x10,0x00,0x19,0x00,0xF2,0xD0,0x10,0x00,0x10,0x00,
		0xF2,0xC0,0x10,0x00,0x1A,0x00,0xB2,0x40,0x42,0xA5,0x2A,0x01,0xF2,0xF0,0xF8,0x00,
		0x22,0x00,0xF2,0xF0,0xF8,0x00,0x21,0x00,0x25,0x43,0x37,0x40,0xBA,0xE5,0x38,0x40,
		0x82,0xE7,0x39,0x40,0x00,0x02,0xA9,0x47,0x00,0x00,0x07,0x55,0x09,0x55,0x08,0x97,
		0xFA,0x23,0x27,0x42,0x30,0x40,0x00,0x02,0xD2,0xB3,0x20,0x00,0xFD,0x2B,0xE2,0xB3,
		0x20,0x00,0xFA,0x2B,0xD2,0xB3,0x20,0x00,0xF7,0x2B,0xE2,0xB3,0x20,0x00,0xFA,0x2F,
		0xD2,0xB3,0x20,0x00,0xFD,0x2F,0x06,0x40,0x06,0x57,0x91,0x3C,0x0E,0x44,0x7E,0xF0,
		0xFE,0x00,0x7E,0x90,0x42,0x00,0xE8,0x23,0x14,0xB3,0x21,0x28,0xD2,0xB3,0x20,0x00,
		0xFD,0x2F,0xE2,0xD3,0x22,0x00,0xD2,0xB3,0x20,0x00,0xFD,0x2B,0x0E,0x43,0x09,0x3C,
		0xD2,0xB3,0x20,0x00,0xFD,0x2F,0xE2,0xD3,0x22,0x00,0xD2,0xB3,0x20,0x00,0xFD,0x2B,
		0x1E,0x53,0x3E,0x92,0xF5,0x3B,0xD2,0xB3,0x20,0x00,0xFD,0x2F,0xE2,0xC3,0x22,0x00,
		0xD2,0xB3,0x20,0x00,0xFD,0x2B,0xD2,0xB3,0x20,0x00,0xFD,0x2F,0x61,0x3C,0x06,0x40,
		0x06,0x57,0x8D,0x3C,0x06,0x40,0x06,0x57,0x62,0x3C,0x06,0x40,0x06,0x57,0x87,0x3C,
		0x14,0x93,0x03,0x20,0x82,0x43,0x20,0x01,0x53,0x3C,0x24,0x93,0x13,0x20,0x06,0x40,
		0x06,0x57,0x55,0x3C,0x0F,0x44,0x06,0x40,0x06,0x57,0x79,0x3C,0x06,0x40,0x06,0x57,
		0x4E,0x3C,0x0E,0x44,0x3E,0xF0,0xFF,0x00,0x8E,0x10,0x0F,0xDE,0x06,0x40,0x06,0x57,
		0x6E,0x3C,0x3E,0x3C,0x34,0x90,0x03,0x00,0x12,0x20,0x06,0x40,0x06,0x57,0x76,0x3C,
		0xB2,0x40,0x02,0xA5,0x28,0x01,0xB2,0x40,0x00,0xA5,0x2C,0x01,0x8F,0x43,0x00,0x00,
		0x92,0xB3,0x2C,0x01,0xFD,0x2F,0x06,0x40,0x06,0x57,0x48,0x3C,0x29,0x3C,0x24,0x92,
		0x13,0x20,0x06,0x40,0x06,0x57,0x2B,0x3C,0x05,0x44,0x06,0x40,0x06,0x57,0x4F,0x3C,
		0x06,0x40,0x06,0x57,0x24,0x3C,0x0E,0x44,0x3E,0xF0,0xFF,0x00,0x8E,0x10,0x05,0xDE,
		0x06,0x40,0x06,0x57,0x44,0x3C,0x14,0x3C,0x34,0x90,0x05,0x00,0x11,0x20,0x06,0x40,
		0x06,0x57,0x4C,0x3C,0xB2,0x40,0x40,0xA5,0x28,0x01,0xB2,0x40,0x00,0xA5,0x2C,0x01,
		0x8F,0x45,0x00,0x00,0x92,0xB3,0x2C,0x01,0xFD,0x2F,0x06,0x40,0x06,0x57,0x1E,0x3C,
		0xD2,0xB3,0x20,0x00,0xFD,0x2B,0xE2,0xB3,0x20,0x00,0x5E,0x2F,0xFC,0x3F,0xD2,0xB3,
		0x20,0x00,0xFD,0x2B,0x34,0x40,0x00,0x01,0x07,0x3C,0x04,0x54,0xD2,0xB3,0x20,0x00,
		0xFD,0x2F,0xD2,0xB3,0x20,0x00,0xFD,0x2B,0xE2,0xB3,0x20,0x00,0x01,0x28,0x14,0x53,
		0x04,0x93,0xF3,0x37,0x34,0xF0,0xFF,0x00,0x00,0x46,0x30,0x41,0xB2,0x40,0x00,0xA5,
		0x28,0x01,0xB2,0x40,0x10,0xA5,0x2C,0x01,0xF2,0x40,0x0D,0x00,0x57,0x00,0xD2,0x42,
		0xFB,0x10,0x57,0x00,0xD2,0x42,0xFA,0x10,0x56,0x00,0x00,0x46,0x30,0x41,0xD2,0xB3,
		0x20,0x00,0xFD,0x2F,0xE2,0xD3,0x22,0x00,0xD2,0xB3,0x20,0x00,0xFD,0x2B,0xD2,0xB3,
		0x20,0x00,0xFD,0x2F,0xE2,0xC3,0x22,0x00,0x00,0x46,0x30,0x41,0xF2,0x40,0x0D,0x00,
		0x57,0x00,0xD2,0x42,0xFF,0x10,0x57,0x00,0xD2,0x42,0xFE,0x10,0x56,0x00,0x00,0x46,
		0x30,0x41,0x30,0x40,0x88,0xE7,0x30,0x40,0x8C,0xE7,0xFF,0x3F
	}, {
		0x52,0xE5
	}
};

unsigned short i2c_upgrader_length[2] = { 572, 2};
#if 0
@E552
31 40 00 04 B0 12 5E E5 B0 12 84 E7 B2 40 80 5A
20 01 F2 40 0D 00 57 00 D2 42 FB 10 57 00 D2 42
FA 10 56 00 F2 C0 10 00 19 00 F2 D0 10 00 10 00
F2 C0 10 00 1A 00 B2 40 42 A5 2A 01 F2 F0 F8 00
22 00 F2 F0 F8 00 21 00 25 43 37 40 BA E5 38 40
82 E7 39 40 00 02 A9 47 00 00 07 55 09 55 08 97
FA 23 27 42 30 40 00 02 D2 B3 20 00 FD 2B E2 B3
20 00 FA 2B D2 B3 20 00 F7 2B E2 B3 20 00 FA 2F
D2 B3 20 00 FD 2F 06 40 06 57 91 3C 0E 44 7E F0
FE 00 7E 90 42 00 E8 23 14 B3 21 28 D2 B3 20 00
FD 2F E2 D3 22 00 D2 B3 20 00 FD 2B 0E 43 09 3C
D2 B3 20 00 FD 2F E2 D3 22 00 D2 B3 20 00 FD 2B
1E 53 3E 92 F5 3B D2 B3 20 00 FD 2F E2 C3 22 00
D2 B3 20 00 FD 2B D2 B3 20 00 FD 2F 61 3C 06 40
06 57 8D 3C 06 40 06 57 62 3C 06 40 06 57 87 3C
14 93 03 20 82 43 20 01 53 3C 24 93 13 20 06 40
06 57 55 3C 0F 44 06 40 06 57 79 3C 06 40 06 57
4E 3C 0E 44 3E F0 FF 00 8E 10 0F DE 06 40 06 57
6E 3C 3E 3C 34 90 03 00 12 20 06 40 06 57 76 3C
B2 40 02 A5 28 01 B2 40 00 A5 2C 01 8F 43 00 00
92 B3 2C 01 FD 2F 06 40 06 57 48 3C 29 3C 24 92
13 20 06 40 06 57 2B 3C 05 44 06 40 06 57 4F 3C
06 40 06 57 24 3C 0E 44 3E F0 FF 00 8E 10 05 DE
06 40 06 57 44 3C 14 3C 34 90 05 00 11 20 06 40
06 57 4C 3C B2 40 40 A5 28 01 B2 40 00 A5 2C 01
8F 45 00 00 92 B3 2C 01 FD 2F 06 40 06 57 1E 3C
D2 B3 20 00 FD 2B E2 B3 20 00 5E 2F FC 3F D2 B3
20 00 FD 2B 34 40 00 01 07 3C 04 54 D2 B3 20 00
FD 2F D2 B3 20 00 FD 2B E2 B3 20 00 01 28 14 53
04 93 F3 37 34 F0 FF 00 00 46 30 41 B2 40 00 A5
28 01 B2 40 10 A5 2C 01 F2 40 0D 00 57 00 D2 42
FB 10 57 00 D2 42 FA 10 56 00 00 46 30 41 D2 B3
20 00 FD 2F E2 D3 22 00 D2 B3 20 00 FD 2B D2 B3
20 00 FD 2F E2 C3 22 00 00 46 30 41 F2 40 0D 00
57 00 D2 42 FF 10 57 00 D2 42 FE 10 56 00 00 46
30 41 30 40 88 E7 30 40 8C E7 FF 3F 
@FFFE
52 E5 
q
#endif
