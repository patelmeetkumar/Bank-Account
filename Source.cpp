#pragma once
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>

using namespace std;

int main() 
{
	bool isRunning = true;
	int number;
	double entry = 0.0;

	SavingsAccount sa;
	CheckingAccount ca;

	while (isRunning)
	{
		cout << "Enter 0 to end the program." << endl;
		cout << "Enter 1 to make a deposit to savings." << endl;
		cout << "Enter 2 to make a deposit to checkings." << endl;
		cout << "Enter 3 to make a withdrawal from savings." << endl;
		cout << "Enter 4 to make a withdrawal from checking." << endl;
		cout << "Enter 5 to view the balance of both accounts." << endl;
		cout << "Enter 6 to indicate a month has passed." << endl;
		cout << "Enter an entry according to instructions above: ";
		cin >> number;
		cout << endl;

		if (number >= 0 && number < 7)
		{
			switch (number)
			{
			case 0: cout << endl << endl << endl << "End of Program!";
					isRunning = false;
				break;

			case 1: cout << "Please enter the amount to deposit to saving account: ";
					cin >> entry;
					sa.deposit(entry);
				break;

			case 2: cout << "Please enter the amount to deposit to checking account: ";
					cin >> entry;
					ca.deposit(entry);
				break;

			case 3: cout << "Please enter the amount to withdraw from saving account: ";
					cin >> entry;
					sa.withdraw(entry);
				break;

			case 4: cout << "Please enter the amount to withdraw from checking account: ";
					cin >> entry;
					ca.withdraw(entry);
				break;

			case 5: cout << "Here's the balance of the saving account: ";
					cout << sa.getBalance() << endl;
					cout << "Here's the balance of the checking account: ";
					cout << ca.getBalance() << endl;
				break;

			case 6: sa.monthlyProc();
					cout << "Here's the monthly service charges for the saving account: ";
					cout << sa.getMonthlyServiceCharges() << endl;
					sa.resetWithdrawals();
					
					ca.monthlyProc();
					cout << "Here's the monthly service charges for the checking account: ";
					cout << ca.getMonthlyServiceCharges() << endl;
					ca.resetWithdrawals();
				break;
			}
		}
		else
		{
			cout << "Invalid entry. Try again!" << endl;
		}

		cout << endl;
	}



	

	return 0;
}