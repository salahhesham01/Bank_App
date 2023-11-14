//
// Created by hsala on 11/3/2022.
//

#ifndef A2_BANKAPP_H
#define A2_BANKAPP_H

#include "cleints.h"
#include "bankAccounts.h"
#include "savingAccounts.h"
#include <fstream>

class Bank
{

public:
    Bank();
    void createAccount();
    void listClients();
    void withdraw();
    void deposit();
    void run();

private:
    vector<Client*> clients;
};



#endif //A2_BANKAPP_H
