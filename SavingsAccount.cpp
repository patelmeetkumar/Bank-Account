#include "SavingsAccount.h"
#include <iostream>

void SavingsAccount::status() 
{
	active = Account::getBalance() >= 25.0;
}

void SavingsAccount::withdraw(double amountWanted)
{
	status();

	if (active) 
	{
		if (((Account::getBalance() - amountWanted) >= 0.0) && amountWanted > 0)
		{
			Account::withdraw(amountWanted);
		}
		else 
		{
			std::cout << "Amount wanted is greater than balance or input is invalid!" << std::endl;
		}
	}
	else 
	{
		std::cout << "The savings account is inactive." << std::endl;
	}

	status();
}

void SavingsAccount::deposit(double amountToDeposit) 
{
	if (amountToDeposit > 0) 
	{
		Account::deposit(amountToDeposit);
	}
	else 
	{
		std::cout << "Please enter a positive value." << std::endl;
	}

	status();
}

void SavingsAccount::monthlyProc() 
{
	double withdrawalCharge = 0.0;
	if (getNumWithdrawal() > 3) 
	{
		double charge = (getNumWithdrawal() - 3);
		withdrawalCharge += charge;
	}
	Account::addMonthlyServiceCharges(withdrawalCharge);

	status();
}