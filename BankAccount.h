
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include "Account.h"

class BankAccount : public Account
{
protected:
    double balance;

public:
    BankAccount();
    BankAccount(int accNo, string name, string phone, double bal);

    void deposit(double amount);
    void withdraw(double amount);
    double getBalance();

    void displayAccount() override;

    virtual void accountFeature() = 0;

    virtual ~BankAccount();
};

#endif