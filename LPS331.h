#ifndef LPS331_h
#define LPS331_h
#include <stdint.h>
#include "I2C_Bus.h"

// register addresses map

/*******BAROMETER***************/

#define LPS331_REF_P_XL       0x08
#define LPS331_REF_P_L        0x09
#define LPS331_REF_P_H        0x0A

#define LPS331_WHO_AM_I       0x0F

#define LPS331_RES_CONF       0x10

#define LPS331_CTRL_REG1      0x20
#define LPS331_CTRL_REG2      0x21
#define LPS331_CTRL_REG3      0x22
#define LPS331_INTERRUPT_CFG  0x23
#define LPS331_INT_SOURCE     0x24
#define LPS331_THS_P_L        0x25
#define LPS331_THS_P_H        0x26
#define LPS331_STATUS_REG     0x27

#define LPS331_PRESS_OUT_XL   0x28
#define LPS331_PRESS_OUT_L    0x29
#define LPS331_PRESS_OUT_H    0x2A

#define LPS331_TEMP_OUT_L     0x2B
#define LPS331_TEMP_OUT_H     0x2C

#define LPS331_AMP_CTRL       0x30

#define LPS331_DELTA_PRESS_XL 0x3C
#define LPS331_DELTA_PRESS_L  0x3D
#define LPS331_DELTA_PRESS_H  0x3E

class LPS331 {

public:

	double preassure, altitude, temp;

	LPS331(const char * i2cDeviceName);

	uint8_t readPreRegister(uint8_t regAddr);
	void writePreRegister(uint8_t regAddr, uint8_t byte);
	void enable(void);

	void readPreassure(void);
	void readTemperature(void);
	void readAltitude(double iso_altitude);

private:

	I2CBus i2c_lps331;
};

#endif
