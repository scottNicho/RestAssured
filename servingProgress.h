#pragma once
#include <string>
#include <iostream>
#include"Timer.h"

using namespace std;


class servingProgress {
public:

	servingProgress();

	~servingProgress();


	int getSP() {
		return SP;
	}

	timer* getTotalOrderTime() {
		return totalOrderTime;
	}

	timer* getTimeBetweenOrders() {
		return TimebetweenOrders;
	}

	enum ServingProgression {
		seated,
		drinksOrder,
		starters,
		main,
		dessert,
		bill
	};



	string getCurrentProgress();

	void ProgressOrder();

protected:

	ServingProgression SP ;

	std::string progress;

	timer* totalOrderTime;
	timer* TimebetweenOrders ;
};