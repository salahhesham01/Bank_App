#include "savingAccounts.h"

SavingsAccount::SavingsAccount(double x, double y):Account(x)
{
	minimumBalance = y;
	if (x < y)
	{
		setBalance(x);
	}
}

void SavingsAccount::deposit(double x)
{
	setBalance(getBalance() + x);
}

bool SavingsAccount::withdraw(double x)
{
	if (x > getBalance())
	{
		cout << "Amount exceeded account balance.Try again" << endl;
		return false;
	}
	else if (getBalance() - x < minimumBalance)
	{
		cout << "Amount exceeded minimum balance.Try again" << endl;
		return false;
	}
	else
	{
		setBalance(getBalance() - x);
		return true;
	}

}

double SavingsAccount::getBalance()
{
	return Account::getBalance();
}

void SavingsAccount::setBalance(double balance)
{
	while (balance < minimumBalance)
	{
		cout << "Error: Initial balance cannot be less than 1000." << endl;
		cout << "Enter the balance again: ";
		cin >> balance;
	}
	Account::setBalance(balance);
}

void SavingsAccount::setAccountNumber(string accountNumber)
{
	this->accountNumber = accountNumber;
}

string SavingsAccount::getAccountNumber()
{
	return accountNumber;
}

