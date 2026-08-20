#ifndef LOAN_H
#define LOAN_H

#include "BankAccount.h"

class Loan : public BankAccount
{
private:
    double interestRate;
    int loanDuration;

public:
    Loan();
    Loan(int accNo, string name, string phone,
         double loanAmount, double rate, int duration);

    void accountFeature() override;

    ~Loan();
};

#endif