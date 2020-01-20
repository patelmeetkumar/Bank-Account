#pragma once
#include "Account.h"

class CheckingAccount : public Account
{
public:
	virtual void withdraw(double amountWanted) override;
	virtual void monthlyProc() override;
};

