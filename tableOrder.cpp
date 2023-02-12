#include "TableOrder.h"

table table_1 = { 1,6,0,false };
table table_2 = { 2,5,0,false };
table table_3 = { 3,4,0,false };
table table_4 = { 4,8,0,false };
table table_5 = { 5,4,0,false };

vector<table> tableOrder::availableTables = {};
vector<table*> tableOrder::TablesInUse = {};
vector<table> tableOrder::TablesToSelect = {};
const vector<table*>tableOrder::allTables = {&table_1,&table_2,&table_3,&table_4,&table_5 };

tableOrder::tableOrder() {
	 assignedTableNumber = 0;
	 exampleUsername = "cloud";
	 examplePassword = "strife";
	 assignedTable = table_1;
	 UsernamePasswordMap[exampleUsername] = examplePassword;
	 
	 
}

