#pragma once

class Account
{
private:
	double balance;
	int numDepositsForMonth;
	int numWithdrawals;
	double annualInterestRate;
	double monthlyServiceCharges;

protected:
	void setBalance(double myBalance) { balance = myBalance; }
	int getNumDepositsForMonth() const { return numDepositsForMonth; }
	int getNumWithdrawal() const { return numWithdrawals; }
	double getAnnualInterestRate() const { return annualInterestRate; }
	void setAnnualInterestRate(int rate) { annualInterestRate = rate; }
	void addMonthlyServiceCharges(double charge) { monthlyServiceCharges += charge; balance -= charge; }

public:
	Account(double balanceAmount = 0, double air = 0);
	virtual void deposit(double amountToDeposit);
	virtual void withdraw(double amountWanted);
	void calcInt();
	virtual void monthlyProc();
	virtual ~Account();
	double getBalance() const { return balance; }
	double getMonthlyServiceCharges() const { return monthlyServiceCharges; }
	void resetWithdrawals() { numWithdrawals = 0; }
	/*
	Need resetWithdrawals() because need to reset numWithdrawals to zero after indicating a month
	has passed. Account's monthlyProc() gets overrrided so it doesn't do it.
	*/
};

