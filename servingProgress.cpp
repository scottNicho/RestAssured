#include"servingProgress.h"
#include "Timer.h"


servingProgress::servingProgress() {
	SP = seated;
	progress = "seated";
	totalOrderTime = new timer();
	TimebetweenOrders = new timer();
}

servingProgress::~servingProgress() {
	delete totalOrderTime;
	delete TimebetweenOrders;
}

string servingProgress::getCurrentProgress() {
	switch (SP) {
	case 0:
		progress = "seated";
		return progress;
	case 1:
		progress = "drinksOrder";
		return progress;
	case 2:
		progress = "starters";
		return progress;
	case 3:
		progress = "main";
		return progress;
	case 4:
		progress = "dessert";
		return progress;
	case 5:
		progress = "bill";
		return progress;
	}
}

void servingProgress::ProgressOrder() {
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