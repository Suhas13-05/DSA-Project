#ifndef SAVINGS_H
#define SAVINGS_H

#include "BankAccount.h"

class Savings : public BankAccount
{
private:
    double interestRate;

public:
    Savings();
    Savings(int accNo, string name, string phone,
             double bal, double rate);

    void accountFeature() override;

    ~Savings();
};

#endif