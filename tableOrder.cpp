#include "TableOrder.h"

table table_1 = { 1,6,0,false };
table table_2 = { 2,5,0,false };
table table_3 = { 3,4,0,false };
table table_4 = { 4,8,0,false };
table table_5 = { 5,4,0,false };

vector<table*> tableOrder::availableTables = {};
vector<table*> tableOrder::TablesInUse = {};
vector<table*> tableOrder::TablesToSelectFrom = {};
const vector<table*>tableOrder::allTables = {&table_1,&table_2,&table_3,&table_4,&table_5 };

tableOrder::tableOrder() {
	 assignedTableNumber = 0;
	 exampleUsername = "cloud";
	 examplePassword = "strife";
	 assignedTable = nullptr;
	 UsernamePasswordMap[exampleUsername] = examplePassword;
	 
	 
}

bool tableOrder::passwordTest() {
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



void tableOrder::checkForTablesInUse() {
	TablesInUse.clear();
	availableTables.clear();
	for (int i(0); i < allTables.size(); i++) {
		if (allTables[i]->occupied) {
			TablesInUse.push_back(allTables[i]);
		}
		else
		{
			availableTables.push_back(allTables[i]);
		}
	}
}

void tableOrder::checkForAvailableTablesNot() {
	for (int ix = 0; ix < availableTables.size(); ix++) {
		if (availableTables[ix]->occupied == true) {
			availableTables.erase(availableTables.begin() + ix);
		}
	}
}

void tableOrder::checkForTablesNotInUse() {
	for (int i(0); i < TablesInUse.size(); i++) {
		if (TablesInUse[i]->occupied == false) {
			TablesInUse.erase(TablesInUse.begin() + i);
		}
	}
}

void tableOrder::updateTablesInUse() {
	checkForTablesInUse();
	checkForTablesNotInUse();
	checkForAvailableTablesNot();
}



table* tableOrder::getTable() {
	while (1) {
		int tableIndex;
		cout << "What table number do you need?" << endl;
		cin >> tableIndex;
		try {
			if (tableIndex > 0 && tableIndex <= allTables.size()) {
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



void tableOrder:: AddToTablesToSelect(unsigned int NumSeatsRequired) {
	for (int yt = 0; yt <= availableTables.size(); yt++) {
		if (availableTables[yt]->numChairs <= NumSeatsRequired) {
			TablesToSelectFrom.push_back(availableTables[yt]);
		}
	}
}
