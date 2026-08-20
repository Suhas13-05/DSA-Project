#include "Account.h"

Account::Account()
{
    accountNumber = 0;
    customerName = "";
    phoneNumber = "";
}

Account::Account(int accNo, string name, string phone)
{
    accountNumber = accNo;
    customerName = name;
    phoneNumber = phone;
}

void Account::displayAccount()
{
    cout << "\nAccount Number : " << accountNumber << endl;
    cout << "Customer Name  : " << customerName << endl;
    cout << "Phone Number   : " << phoneNumber << endl;
}

Account::~Account()
{
}