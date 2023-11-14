//
// Created by hsala on 11/3/2022.
//

#ifndef A2_CLIENTS_H
#define A2_CLIENTS_H

#include "bankAccounts.h"
#include "savingAccounts.h"



class Client
{
public:
    Client(string, string, string, string, Account*);
    Client(string, string, string, string, SavingsAccount*);
    void setName(string);
    void setAddress(string);
    void setPhone(string);
    void setAccount(Account*);
    void setAccount(SavingsAccount*);
    void setID(string);

    string getName();
    string getAddress();
    string getPhone();
    Account* getAccount();
    string getType();
    string getID();
	SavingsAccount* getSavingsAccount();
	
private:

    string name;
    string address;
    string phone;
    string type;
    Account* account;
	SavingsAccount* savingsAccount;
    string ID;

};



#endif //A2_CLIENTS_H
