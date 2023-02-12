#pragma once
#include <string>
#include<vector>
#include<iostream>
#include<map>
#include"order.h"

using namespace std;


struct table {
	unsigned int tableNumber;
	unsigned int numChairs;
	unsigned int numberOfPeople;
	bool occupied;

private:
	order* ThisTablesOrder = nullptr;
};





class tableOrder {
public:

	tableOrder();
	
	int getSP() {
		return SP;
	}

	enum ServingProgress {
		seated,
		drinksOrder,
		starters,
		main,
		dessert,
		bill
	};

	

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

	bool passwordTest();

	void checkForTablesInUse();

	void checkForAvailableTablesNot();

	void checkForTablesNotInUse();

	void updateTablesInUse();

	table* getTable();

	void AddToTablesToSelect(unsigned int NumSeatsRequired);

	void startTableOrder(table *TableToInitilise) {

	}
    


//protected:

	unsigned int assignedTableNumber;

	map<string, string> UsernamePasswordMap;

	string exampleUsername;
	string examplePassword;

	table* assignedTable;

	static vector<table*> availableTables;
	static vector<table*> TablesInUse;
	static vector<table*> TablesToSelectFrom; //tables big enought for the party
	static const vector<table*>  allTables;
	
	ServingProgress SP = seated;

	std::string progress;
};
	

