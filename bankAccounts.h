//
// Created by hsala on 11/3/2022.
//

#ifndef A2_BANKACCOUNTS_H
#define A2_BANKACCOUNTS_H


#include <iostream>
#include <string>
#include <vector>



using namespace std;


class Account
{
public:
    Account(double);

    void deposit(double);                  
    bool withdraw(double);                  
    double getBalance();

    void setBalance(double);
    void setAccountNumber(string);
    string getAccountNumber();

private:
    double balance;
    string accountNumber = "FCAI-";
   
};



#endif //A2_BANKACCOUNTS_H
