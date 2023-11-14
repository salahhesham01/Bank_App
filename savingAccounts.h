//
// Created by hsala on 11/3/2022.
//

#ifndef A2_SAVINGACCOUNTS_H
#define A2_SAVINGACCOUNTS_H

#include "bankAccounts.h"


class SavingsAccount : public Account
{
public:
    SavingsAccount(double, double);

    void deposit(double);                  
    bool withdraw(double);                   
    double getBalance();

    void setBalance(double);
    void setAccountNumber(string);
    string getAccountNumber();
private:

    double minimumBalance = 1000;
    string accountNumber = "FCAI-";

};


#endif //A2_SAVINGACCOUNTS_H
