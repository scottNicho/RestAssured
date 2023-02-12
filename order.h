#pragma once
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include<map>
#include "CashRegister.h"

using namespace std;


struct timer {

	timer(){
		toggleTimerOn();
		timing();
	}

	bool timerOn = false;
	int seconds = 0;
	int tenSeconds = 0;
	int minutes = 0;
	int tenMinutes = 0;
	int hours = 0;

	void toggleTimerOn() {
		if (timerOn == false) {
			timerOn = true;
		}
		else
		{
			timerOn = false;
		}
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

	void resetTimer() {  // resets the full timer
		resetSeconds();
		resetTenSeconds();
		resetMinutes();
		resetTenMinutes();
		resetHours();
	}

	void timing() {
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

};


struct menuItems {
	float price;
	string itemDescription;
};

//instances of menuItems
//struct menuItems Arrabbiata {
//	10.90f,
//    "Spicy tomato garlic sauce and spirali with roasted red pepper, red onion, chillies & rocket"
//
//};
//
//struct menuItems Margherita {
//	9.90f,
//    "Tomato and mozzarella"
//};
//   
//struct menuItems Sirloin_Steak {
//	18.90,
//    "Our 8oz* sirloin steak, sautéed mushrooms, roasted tomato & onion rings"
//};
//
////instances of menuItems

struct specialDeals {
	vector <menuItems> special = {};
	void addTospecial(menuItems itemForSpecial) {
		special.push_back(itemForSpecial);
	}

	vector<menuItems> getSpecial() {
		return special;
	}
};




class order {
public:

	order();

	~order();

	timer *OrderTime;
	timer *timeBetweenOrders;
	
	void addItemToOrder(menuItems selectedItem) {
		currentOrder.push_back(selectedItem);
	}

	void removeItemFromOrder();

	void addItemToTotalOrder(menuItems selectedItem) {
		totalOrder.push_back(selectedItem);
	}

	void removeItemFromTotalOrder();

	void addItemToMenueMap();

	void AddItemPriceToRunningCost(int ItemCost) {
		costtings->AddToRunningPrice(ItemCost);
	}

	//menue map size for testing
	int getMenueMapSize() {
		return menueMap.size();
	}

protected:

	map<string,menuItems> menueMap;
	vector<menuItems> totalOrder;
	vector<menuItems> currentOrder;
	CashRegister* costtings;


};
