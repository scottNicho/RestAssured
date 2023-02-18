#pragma once
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include<map>
#include "CashRegister.h"
#include"servingProgress.h"

using namespace std;



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

	
	servingProgress* getOrderProgress() {
		return orderProgress;
	}

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
	servingProgress* orderProgress;

};
