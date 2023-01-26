#pragma once
#include <iostream>
#include <string>

class CashRegister {
public:

	void SetMessage(std:: string messageToReturn) {
		message = messageToReturn;
	}

	std::string GetMessage() {
		return message;
	}

	void AddToRunningPrice(double amount) {
		runningPrice += amount;
	}

	void MannualAddToDeductions(double amount) {
		deductions += amount;
	}

	static double GetDeductions() {
		return deductions;
	}

	void FixedAmountOff(double dis) {
		deductions += dis;
	}

	void SetPercentageOff(double percentded){
		PercentageOff = 1 - percentded;
	}

	void setTotalPrice() {
		totalPrice = (runningPrice - deductions) * PercentageOff;
	}

	static double GetTotalPrice() {
		return totalPrice;
	}

	void toggleDiscountOrCode() {
		if (discountOrCode == true) {
			discountOrCode = false;
		}
		else
		{
			discountOrCode = true;
		}
	}

	double GetDiscountOrCode() {
		return discountOrCode;
	}

	void togglePayWithCard() {
		if (payWithCard == true) {
		 payWithCard = false;
		}
		else
		{
			payWithCard = true;
		}
	}


	bool GetPayWithCard() {
		return payWithCard;
	}

	void ToggleSplit() {
		if (split == true) {
			split = false;
		}
		else
		{
			split = true;
		}

	}

	bool GetSplit() {
		return split;
	}

	void setCashPayed(double cashAmount) {
		CashPaid = cashAmount;
	}

	void PaymentAndChangeDue() {
		if (CashPaid - totalPrice < 0) {
			PaySucess = false;
			SetMessage("not");
		}
		else
		{
			changeDue = (CashPaid - totalPrice);
			PaySucess = true;

		}
	}

	static double GetChangeDue() {
		return changeDue;
	}


protected:

	static std::string message;

	static double CashPaid;
	static double runningPrice;
	static double deductions;
	static double totalPrice;
	static double PercentageOff;
	static double changeDue;

	static bool discountOrCode;
	static bool payWithCard;
	static bool PaySucess;
	static bool split;
	

};