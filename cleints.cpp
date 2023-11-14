//
// Created by hsala on 11/3/2022.
//

#include "cleints.h"

Client::Client(string name, string address, string phone, string type, Account* account)
{
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->account = account;
    this->type = type;
}

Client::Client(string name, string address, string phone, string type, SavingsAccount* savingsAccount)
{
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->savingsAccount = savingsAccount;
    this->type = type;
}

void Client::setName(string name)
{
    this->name = name;
}

void Client::setAddress(string address)
{
    this->address = address;
}

void Client::setPhone(string phone)
{
    this->phone = phone;
}

void Client::setAccount(Account* account)
{
    this->account = account;
}

void Client::setAccount(SavingsAccount* savingsAccount)
{
    this->savingsAccount =  savingsAccount;

}

void Client::setID(string ID)
{
	this->ID = ID;
}

string Client::getName()
{
    return name;
}

string Client::getAddress()
{
    return address;
}

string Client::getPhone()
{
    return phone;
}

Account* Client::getAccount()
{
    return account;
}

SavingsAccount* Client::getSavingsAccount()
{
	return savingsAccount;
}

string Client::getType()
{
    return type;
}

string Client::getID()
{
    if (getType() == "Basic")
    {
		return account->getAccountNumber();
	}
	
	else if (getType() == "Savings")
	{
		return savingsAccount->getAccountNumber();
	}

}

