#include "LPS331.h"
#include <stdio.h>
#include <unistd.h>

int main(void) {
	uint8_t bajt;
	const char *fileN = "/dev/i2c-1";

	LPS331 lps331(fileN);

	lps331.enable();

	double iso_altitude = 1019.2; // 1013.25

	while (1) {
		lps331.readPreassure();
		lps331.readTemperature();
		lps331.readAltitude(iso_altitude);
		printf("preasure: \e[27;1;31m %g \e[m hPa.\n", lps331.preassure);
		printf("Temperature: \e[27;1;31m %g \e[m\n", lps331.temp);
		printf("Altitude: \e[27;1;31m %g \e[m mts.\n", lps331.altitude);
		sleep(1);
	}

}

