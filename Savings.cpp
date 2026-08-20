#include "Savings.h"

Savings::Savings() : BankAccount()
{
    interestRate = 4.0;
}

Savings::Savings(int accNo, string name, string phone,
                 double bal, double rate)
    : BankAccount(accNo, name, phone, bal)
{
    interestRate = rate;
}

void Savings::accountFeature()
{
    cout << "\n========== SAVINGS ACCOUNT ==========\n";

    displayAccount();

    double interest = balance * interestRate / 100;

    cout << "Interest Rate : " << interestRate << "%\n";
    cout << "Interest Earned : ₹" << interest << endl;
}

Savings::~Savings()
{
}