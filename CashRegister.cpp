#include"CashRegister.h"




std::string CashRegister::message = "";

double CashRegister::CashPaid = 0.0f;
double CashRegister::runningPrice = 0.0f;
double CashRegister::deductions = 0.0f;
double CashRegister::totalPrice = 0.0f;
double CashRegister::PercentageOff = 1.0f;
double CashRegister::changeDue = 0.0f;

bool CashRegister::discountOrCode = false;
bool CashRegister::payWithCard = false;
bool CashRegister::PaySucess = false;
bool CashRegister::split = false;