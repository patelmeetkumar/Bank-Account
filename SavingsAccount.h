#pragma once
#include "Account.h"

class SavingsAccount : public Account
{
private:
	bool active = false;

public:
	void status();
	virtual void withdraw(double amountWanted) override;
	virtual void deposit(double amountToDeposit) override;
	virtual void monthlyProc() override;
};

