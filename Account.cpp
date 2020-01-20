#include "Account.h"
#include <iostream>

Account::Account(double balanceAmount, double air)
{
	balance = balanceAmount;
	annualInterestRate = air;
	monthlyServiceCharges = 0.0;
	numWithdrawals = 0;
	numDepositsForMonth = 0;
}

void Account::deposit(double amountToDeposit) 
{
	if (amountToDeposit > 0)
	{
		balance += amountToDeposit;
		numDepositsForMonth++;
	}
	else
	{
		std::cout << "Please enter a positive value." << std::endl;
	}

}

void Account::withdraw(double amountWanted) 
{
	if (amountWanted > 0) 
	{
		balance -= amountWanted;
		numWithdrawals++;
	}
	else 
	{
		std::cout << "Please enter a positive value." << std::endl;
	}

}

void Account::calcInt() 
{
	double monthlyInterestRate = annualInterestRate / 12.0;
	double monthlyInterestAmount = balance * monthlyInterestRate;
	balance += monthlyInterestAmount;
}
void Account::monthlyProc() 
{
	balance -= monthlyServiceCharges;
	calcInt();
	numWithdrawals = 0;
	numDepositsForMonth = 0;
	monthlyServiceCharges = 0.0;
}

Account::~Account()
{
}
