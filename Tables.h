#pragma once
#include <string>


class table {
public:

	static unsigned int tableNumber;
	static unsigned int numChairs;
	static unsigned int numberOfPeople;
	static bool occupied;


	void toggleOccupied() {
		if (occupied == true) {
			occupied = false;
		}
		else
		{
			occupied = true;
		}
	}

	std::string progress;

	void setNumChairs(int newChairNum) {
		numChairs = newChairNum;
	}

	void setTableNumber(int assignTableNum) {
		tableNumber = assignTableNum;
	}

	static int getTablenumber() {
		return tableNumber;
	}

	static int getNumberOfChairs() {
		return numChairs;
	}

	void setBumberOfPeople(int addNumPeople) {
		numberOfPeople = addNumPeople;
	}

	enum ServingProgress {
		seated,
		drinksOrder,
		starters,
		main,
		dessert,
		bill
	};

	ServingProgress SP = seated;


	void getCurrentProgress() {
		switch (SP) {
		case 0:
			progress = "seated";
			break;
		case 1:
			progress = "drinksOrder";
			break;
		case 2:
			progress = "starters";
			break;
		case 3:
			progress = "main";
			break;
		case 4:
			progress = "dessert";
			break;
		case 5:
			progress = "bill";
			break;
		}
	}

	void ProgressOrder() {
		switch (SP) {
		case 0:
			SP = drinksOrder;
			break;
		case 1:
			SP = starters;
			break;
		case 2:
			SP = main;
			break;
		case 3:
			SP = dessert;
			break;
		case 4:
			SP = dessert;
			break;
		case 5:
			SP = bill;
			progress = "finished";
			break;
		}
	}


	int GetSP() {
		return SP;
	}





};
	


