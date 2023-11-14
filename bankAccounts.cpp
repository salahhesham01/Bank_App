//
// Created by hsala on 11/3/2022.
//

#include "bankAccounts.h"

Account::Account(double balance)
{
	this->balance = balance;
}


void Account::deposit(double amount)
{
	balance += amount;
}

bool Account::withdraw(double amount)
{
	if (balance - amount >= 0)
	{
		balance -= amount;
		return true;
	}
	else
	{
		cout << "Insufficient Balance" << endl;
		return false;
	}
}

double Account::getBalance()
{
	return balance;
}

void Account::setBalance(double balance)
{
	this->balance = balance;
}

void Account::setAccountNumber(string accountNumber)
{
	this->accountNumber = accountNumber;
}

string Account::getAccountNumber()
{
	return accountNumber;
}

