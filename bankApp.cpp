#include "bankApp.h"


Bank::Bank()
{
	
}



void Bank::createAccount()
{
	
    string name, address, phone, accountID, type;
    int accountType;
    double initialBalance;
    static int accountNumber = clients.size()+1;

    cout << "Please Enter Client Name =========> ";
    getline(cin >> ws, name);
    cout << "Please Enter Client Address =========> ";
    getline(cin >> ws, address);
    cout << "Please Enter Client Phone =========> ";
    getline(cin >> ws, phone);

    cout << "Please Enter Account Type (1 for Basic, 2 for Savings) =========> ";
    cin >> accountType;


    if (accountType == 1)
    {
        cout << "Please Enter Initial Balance =========> ";
        cin >> initialBalance;
        type = "Basic";
		Account* account = new Account(initialBalance);
        if (accountNumber < 10)
        {
            accountID = "FCAI-00" + to_string(accountNumber);
        }
        else if (accountNumber < 100)
        {
            accountID = "FCAI-0" + to_string(accountNumber);
        }
        else
        {
            accountID = "FCAI-" + to_string(accountNumber);
        }
        account->setAccountNumber(accountID);
        Client* client = new Client(name, address, phone, type, account);
        clients.push_back(client);
        cout << "An account has been created with ID: " << accountID << " and Balance: " << account->getBalance() << endl;
       // accountNumber++;
    }
    else if (accountType == 2)
    {    
		cout<< "Please Enter Initial Balance =========> ";
		cin >> initialBalance;
		type = "Savings";
		SavingsAccount* savingsAccount = new SavingsAccount(initialBalance,1000);
        if (accountNumber < 10)
        {
            accountID = "FCAI-00" + to_string(accountNumber);
        }
		else if (accountNumber < 100)
		{
			accountID = "FCAI-0" + to_string(accountNumber);
		}
		else
		{
			accountID = "FCAI-" + to_string(accountNumber);
		}
		savingsAccount->setAccountNumber(accountID);
		Client* client = new Client(name, address, phone, type, savingsAccount);
		clients.push_back(client);
		cout << "An account has been created with ID: " << accountID << " and Balance: " << savingsAccount->getBalance() << endl;
    }
}

void Bank::listClients()
{
    for (int i = 0; i < clients.size(); i++)
    {
        cout << "----------------- " << clients[i]->getName()<<" ----------------- "<< endl;
        cout << "Adress : " << clients[i]->getAddress() << ". ,";
        cout << " Phone : " << clients[i]->getPhone() << endl;
        if (clients[i]->getType() == "Basic")
        {
            cout << "Account ID: " << clients[i]->getAccount()->getAccountNumber() << " " << "(" << clients[i]->getType() << ")" << endl;
            cout << "Account Balance: " << clients[i]->getAccount()->getBalance() << endl;
        }
        else if (clients[i]->getType()=="Savings")
        {
            cout << "Account ID: " << clients[i]->getSavingsAccount()->getAccountNumber() << " " << "(" << clients[i]->getType() << ")" << endl;
            cout << "Account Balance: " << clients[i]->getSavingsAccount()->getBalance() << endl;
        }
		
        
        cout << "-----------------------------------------------" << endl;
    }
}
void Bank::withdraw() {
    string accountID;
    double amount;
    cout << "Please Enter Account ID (e.g., FCAI-015) =========> ";
    cin >> accountID;
    cout << "Please Enter Amount =========> ";
    cin >> amount;
    for (int i = 0; i < clients.size(); i++)
    {
        if (clients[i]->getID() == accountID)
        {
            if (clients[i]->getType() == "Basic")
            {
                if (clients[i]->getAccount()->withdraw(amount))
                {
                    cout << "Withdrawal Successful" << endl;
                    cout << "Account Balance =========> " << clients[i]->getAccount()->getBalance() << endl;
                    break;
                }
				else
				{
					withdraw();
				}
            }
            else if (clients[i]->getType() == "Savings")
            {
                if (clients[i]->getSavingsAccount()->withdraw(amount))
                {
                    cout << "Withdrawal Successful" << endl;
                    cout << "Account Balance =========> " << clients[i]->getSavingsAccount()->getBalance() << endl;
                    break;
                }
                else
                {
					withdraw();
                }

            }

        }

    }
}

void Bank::deposit()
{
    string accountNumber;
    double amount;

    cout << "Please Enter Account ID (e.g., FCAI-015) =========> ";
    cin >> accountNumber;
    cout << "Please Enter Amount =========> ";
    cin >> amount;

    for (int i = 0; i < clients.size(); i++)
    {
        Client* client = clients[i];
		if (client->getID()== accountNumber)
		{
			if (client->getType() == "Basic")
			{
				client->getAccount()->deposit(amount);
                cout << "Deposit Successful" << endl;
                cout << "Account Balance =========> " << client->getAccount()->getBalance() << endl;
                break;
            }
			else if (client->getType() == "Savings")
			{
				client->getSavingsAccount()->deposit(amount);
				cout << "Deposit Successful" << endl;
				cout << "Account Balance =========> " << client->getSavingsAccount()->getBalance() << endl;
				break;
            }

		}
    }
    cout << "Account Not Found" << endl;
}

void Bank::run()
{
    int choice;

    while (true)
    {
        cout << "Welcome to FCAI Banking Application" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. List Clients" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Deposit" << endl;
        cout << "5. Exit" << endl;
        cout << "Please Enter Your Choice =========> ";
        cin >> choice;
		

        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            listClients();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            deposit();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid Choice" << endl;
        }
    }

}
