#include "Loan.h"

Loan::Loan() : BankAccount()
{
    interestRate = 8.5;
    loanDuration = 12;
}

Loan::Loan(int accNo, string name, string phone,
           double loanAmount, double rate, int duration)
    : BankAccount(accNo, name, phone, loanAmount)
{
    interestRate = rate;
    loanDuration = duration;
}

void Loan::accountFeature()
{
    cout << "\n========== LOAN ACCOUNT ==========\n";

    displayAccount();

    double totalAmount = balance + (balance * interestRate / 100);
    double emi = totalAmount / loanDuration;

    cout << "Interest Rate : " << interestRate << "%\n";
    cout << "Loan Duration : " << loanDuration << " months\n";
    cout << "Monthly EMI   : ₹" << emi << endl;
}

Loan::~Loan()
{
}