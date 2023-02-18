#include "timer.h"

timer::timer() {
	timerOn = true;
	seconds = 0;
	tenSeconds = 0;
	minutes = 0;
	tenMinutes = 0;
	hours = 0;

	timing();
}

void timer::resetTimer() {  // resets the full timer
	resetSeconds();
	resetTenSeconds();
	resetMinutes();
	resetTenMinutes();
	resetHours();
}


void timer::timing() {
	while (timerOn) {
		seconds++;
		if (seconds == 10) {
			resetSeconds();
			tenSeconds++;
			if (tenSeconds == 6) {
				resetTenSeconds();
				minutes++;
				if (minutes == 10) {
					resetMinutes();
					tenMinutes++;
					if (tenMinutes == 6) {
						resetTenMinutes();
						hours++;
					}
				}
			}
		}
		cout << hours << ": " << tenMinutes << minutes << ": " << tenSeconds << seconds << endl;
		Sleep(1000);
	}
}