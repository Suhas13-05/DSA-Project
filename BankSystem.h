#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include <iostream>
#include <unordered_map>
#include <fstream>

#include "Savings.h"
#include "Current.h"
#include "Loan.h"

using namespace std;

class BankSystem
{
private:
    unordered_map<int, Account*> accounts;

public:
    BankSystem();

    void createAccount();
    void displayAllAccounts();
    void searchAccount();

    void depositMoney();
    void withdrawMoney();
    void checkBalance();
    void deleteAccount();

    void saveToFile();
    void loadFromFile();

    void menu();

    ~BankSystem();
};

#endif