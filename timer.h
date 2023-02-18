#pragma once
#include<iostream>
#include <windows.h>

using namespace std;

class timer {
public:

	timer();

	bool timerOn;
	int seconds;
	int tenSeconds;
	int minutes;
	int tenMinutes;
	int hours;

	void toggleTimer() {
		timerOn = (!timerOn);
	}

	void PrintCurrentTime() {
		cout << seconds << " " << tenSeconds << " " << minutes << " " << tenMinutes << " " << hours << endl;
	}

	void resetSeconds() {
		seconds = 0;
	}

	void resetTenSeconds() {
		tenSeconds = 0;
	}

	void resetMinutes() {
		minutes = 0;
	}

	void resetTenMinutes() {
		tenMinutes = 0;
	}
	void resetHours() {
		hours = 0;
	}

	void resetTimer();  // resets the full timer
		

	void timing();

};
