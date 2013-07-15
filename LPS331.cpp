#include "LPS331.h"
#include <math.h>
#include <stdio.h>

#define LPS331_BAR_ADDRESS            (0xBA >> 1)

LPS331::LPS331(const char * i2cDeviceName) : i2c_lps331(i2cDeviceName) {

	preassure = 0, altitude = 0, temp = 0;
}

void LPS331::enable(void) {

	writePreRegister(LPS331_CTRL_REG1, 0b11100000);
}

uint8_t LPS331::readPreRegister(uint8_t regAddr) {

	i2c_lps331.addrSet(LPS331_BAR_ADDRESS);
	return i2c_lps331.readByte(regAddr);
}

void LPS331::writePreRegister(uint8_t regAddr, uint8_t byte) {

	i2c_lps331.addrSet(LPS331_BAR_ADDRESS);
	i2c_lps331.writeByte(regAddr, byte);

}

void LPS331::readPreassure(void) {
	uint8_t block[6];

	i2c_lps331.addrSet(LPS331_BAR_ADDRESS);

	i2c_lps331.readBlock(0x80 | LPS331_PRESS_OUT_XL, sizeof(block), block);

	uint8_t p_xl_raw = (uint8_t) block[0];
	uint8_t p_l_raw = (uint8_t) block[1];
	uint8_t p_h_raw = (uint8_t) block[2];

	int32_t result = (int32_t) p_h_raw << 16 | (uint16_t) p_l_raw << 8 | p_xl_raw;
	preassure = (double) result / 4096;
}

void LPS331::readTemperature(void) {
	uint8_t block[6];

	i2c_lps331.addrSet(LPS331_BAR_ADDRESS);

	i2c_lps331.readBlock(0x80 | LPS331_TEMP_OUT_L, sizeof(block), block);

	uint8_t t_l_raw = (uint8_t) block[0];
	uint8_t t_h_raw = (uint8_t) block[1];

	int16_t result = ((int16_t) t_h_raw << 8 | t_l_raw);
	temp = 42.5 + result / 480;
}

void LPS331::readAltitude(double iso_altitude) {

	altitude = (1 - pow(preassure / iso_altitude, 0.190263)) * 44330.8;
}
