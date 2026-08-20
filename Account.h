
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    int accountNumber;
    string customerName;
    string phoneNumber;

public:
    Account();
    Account(int accNo, string name, string phone);

    virtual void displayAccount();
    virtual void accountFeature() = 0;

    virtual ~Account();
};

#endif