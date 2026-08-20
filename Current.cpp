#include "Current.h"

Current::Current() : BankAccount()
{
    overdraftLimit = 10000;
}

Current::Current(int accNo, string name, string phone,
                 double bal, double limit)
    : BankAccount(accNo, name, phone, bal)
{
    overdraftLimit = limit;
}

void Current::accountFeature()
{
    cout << "\n========== CURRENT ACCOUNT ==========\n";

    displayAccount();

    cout << "Overdraft Limit : ₹" << overdraftLimit << endl;
}

Current::~Current()
{
}