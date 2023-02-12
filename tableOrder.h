#pragma once
#include <string>
#include<vector>
#include<iostream>
#include<map>

using namespace std;


struct table {
	unsigned int tableNumber;
	unsigned int numChairs;
	unsigned int numberOfPeople;
	bool occupied;


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

	ServingProgress SP = seated;

	std::string progress;

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

	bool passwordTest() {
		string tryUserName;
		string tryPassword;
		cout << "please enter your username" << endl;
		cin >> tryUserName;
		cout << "please enter your password" << endl;
		cin >> tryPassword;
		if (UsernamePasswordMap[tryUserName] == tryPassword) {
			return true;
		}
		return false;
	}

	void checkForTablesInUse() {
		TablesInUse.clear();
		for (int i(0); i < allTables.size(); i++) {
			if (allTables[i]->occupied) {
				TablesInUse.push_back(allTables[i]);
			}
		}
	}

	void checkForTablesNotInUse() {
		for (int i(0); i < TablesInUse.size(); i++) {
			if (TablesInUse[i]->occupied == false) {
				TablesInUse.erase(TablesInUse.begin() + i);
			}
		}
	}

	void updateTablesInUse() {
		checkForTablesInUse();
		checkForTablesNotInUse();
	}

	table* getTable() {
		while (1) {
			int tableIndex;
			cout << "What table number do you need?" << endl;
			cin >> tableIndex;
			try {
				if (tableIndex > 0) {
					return allTables[tableIndex - 1];
				}
				else
				{
					throw(tableIndex);
				}
			}
			catch (int lowTableNum) {
				cout << "table number is too low. \n please input a valid table number" << endl;
			}
		}
	}

	//instantiate tables
    


protected:

	unsigned int assignedTableNumber;

	map<string, string> UsernamePasswordMap;

	string exampleUsername;
	string examplePassword;

	table assignedTable;

	static vector<table> availableTables;
	static vector<table*> TablesInUse;
	static vector<table> TablesToSelect;
	static const vector<table*>  allTables;
	

};
	


