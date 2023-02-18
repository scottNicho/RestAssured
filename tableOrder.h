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
	order* ThisTablesOrder;

	table(unsigned int tnum, unsigned int nchairs, unsigned int nppl, bool occ)
		: tableNumber(tnum), numChairs(nchairs), numberOfPeople(nppl), occupied(occ), ThisTablesOrder(new order) {}

	~table() {
		delete ThisTablesOrder;
	}
};





class tableOrder {
public:

	tableOrder();
	
	

	bool passwordTest();

	void checkForTablesInUse();

	void checkForAvailableTablesNot();

	void checkForTablesNotInUse();

	void updateTablesInUse();

	table* getTable();

	table* getTable2(unsigned int tabNum);

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
	
	
};
	


