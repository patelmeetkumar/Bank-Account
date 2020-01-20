#include "CheckingAccount.h"
#include <iostream>

void CheckingAccount::withdraw(double amountWanted) 
{
	if (amountWanted < 0 || (Account::getBalance() - amountWanted) <= 0.0) 
	{
		Account::addMonthlyServiceCharges(15.0);
		std::cout << "Withdraw cannot be performed because of low balance or input is invalid." << std::endl;
	}
	else 
	{
		Account::withdraw(amountWanted);
	}
}

void CheckingAccount::monthlyProc() 
{
	double withdrawalCharge = 5.0;
	withdrawalCharge += (getNumWithdrawal() * 0.1);
	Account::addMonthlyServiceCharges(withdrawalCharge);
}