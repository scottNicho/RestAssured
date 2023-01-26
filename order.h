#pragma once
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include<map>

using namespace std;


struct timer {

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
	int quantity;
	int price;
	string itemDescription;
};

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


	timer OrderTime;
	
	void addItemToOrder(menuItems selectedItem) {
		currentOrder.push_back(selectedItem);
	}

	void removeItemFromOrder() {
		if (currentOrder.size() == 0) {
			exit(0);
		}
		currentOrder.pop_back();
	}

	void addItemToTotalOrder(menuItems selectedItem) {
		totalOrder.push_back(selectedItem);
	}

	void removeItemFromTotalOrder() {
		if (totalOrder.size() == 0) {
			exit(0);
		}
		totalOrder.pop_back();
	}

	void addItemToMenueMap() {
		string newItemName;
		string newItemDescription;
		int newItemCost;
		cout << "What is the name of the item you wish to add?" << endl;
		getline(cin, newItemName);
		menueMap[newItemName];
		cout << "Thank you. What is the cost of the item please?"<<endl;
		cin >> newItemCost;
		menueMap[newItemName].price = newItemCost;
		cout << "thank you. Please give a succinct description of the item";
		getline(cin, newItemDescription);
		menueMap[newItemName].itemDescription = newItemDescription;
		cout << menueMap.size();
	}


	void AddItemPriceToRunningCost(int ItemCost) {
		costtings->AddToRunningPrice(ItemCost);
	}



protected:

	map<string,menuItems> menueMap;
	vector<menuItems> totalOrder;
	vector<menuItems> currentOrder;
	CashRegister* costtings;


};