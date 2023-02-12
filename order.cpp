#include "order.h"

order::order() {

	totalOrder = {};
	currentOrder = {};
	costtings = new CashRegister();
	menueMap["Arrabbiata"] = menuItems{10.90,"Spicy tomato garlic sauce and spirali with roasted red pepper, red onion, chillies & rocket"};
	menueMap["Margherita"] = menuItems{ 9.90,"Tomato and mozzarella" };
	menueMap["Sirloin Steak"] = menuItems{ 18.90,"Our 8oz* sirloin steak, sautéed mushrooms, roasted tomato & onion rings" };
}

order::~order() {
	delete costtings;
}

void order::removeItemFromOrder() {
	if (currentOrder.size() == 0) {
		exit(0);
	}
	currentOrder.pop_back();
}


void order::removeItemFromTotalOrder() {
	if (totalOrder.size() == 0) {
		exit(0);
	}
	totalOrder.pop_back();
}


void order::addItemToMenueMap() {
	string newItemName;
	string newItemDescription;
	float newItemCost;
	cout << "What is the name of the item you wish to add?" << endl;
	getline(cin, newItemName);
	menueMap[newItemName];
	cout << "thank you. Please give a succinct description of the item" << endl;
	getline(cin, newItemDescription);
	menueMap[newItemName].itemDescription = newItemDescription;
	cout << "Thank you. What is the cost of the item please?" << endl;
	cin >> newItemCost;
	menueMap[newItemName].price = newItemCost;
	cout << menueMap[newItemName].price << endl;
	cout << menueMap.size();
}