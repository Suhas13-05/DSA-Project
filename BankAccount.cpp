#include "BankAccount.h"

BankAccount::BankAccount() : Account()
{
    balance = 0;
}

BankAccount::BankAccount(int accNo, string name, string phone, double bal)
    : Account(accNo, name, phone)
{
    balance = bal;
}

void BankAccount::deposit(double amount)
{
    balance += amount;
    cout << "₹" << amount << " deposited successfully.\n";
}

void BankAccount::withdraw(double amount)
{
    if (amount <= balance)
    {
        balance -= amount;
        cout << "₹" << amount << " withdrawn successfully.\n";
    }
    else
    {
        cout << "Insufficient Balance!\n";
    }
}

double BankAccount::getBalance()
{
    return balance;
}

void BankAccount::displayAccount()
{
    Account::displayAccount();
    cout << "Balance        : ₹" << balance << endl;
}

BankAccount::~BankAccount()
{
}