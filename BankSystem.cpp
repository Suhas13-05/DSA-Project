#include "BankSystem.h"

BankSystem::BankSystem()
{
    
}

void BankSystem::createAccount()
{
    int type;
    int accNo;
    string name, phone;
    double balance;

    cout << "\n===== CREATE ACCOUNT =====\n";
    cout << "1. Savings\n";
    cout << "2. Current\n";
    cout << "3. Loan\n";

    cout << "Choose Account Type: ";
    cin >> type;

    cout << "Account Number: ";
    cin >> accNo;

    if(accounts.find(accNo) != accounts.end())
    {
        cout << "Account Number Already Exists!\n";
        return;
    }

    cout << "Customer Name: ";
    cin >> name;

    cout << "Phone Number: ";
    cin >> phone;

    cout << "Initial Balance / Loan Amount: ";
    cin >> balance;

    if(type == 1)
    {
        double rate;
        cout << "Interest Rate: ";
        cin >> rate;

        accounts[accNo] = new Savings(accNo, name, phone, balance, rate);
    }
    else if(type == 2)
    {
        double limit;
        cout << "Overdraft Limit: ";
        cin >> limit;

        accounts[accNo] = new Current(accNo, name, phone, balance, limit);
    }
    else if(type == 3)
    {
        double rate;
        int duration;

        cout << "Interest Rate: ";
        cin >> rate;

        cout << "Loan Duration (Months): ";
        cin >> duration;

        accounts[accNo] = new Loan(accNo, name, phone, balance, rate, duration);
    }
    else
    {
        cout << "Invalid Account Type!\n";
        return;
    }

    cout << "\nAccount Created Successfully!\n";
}

void BankSystem::displayAllAccounts()
{
    if(accounts.empty())
    {
        cout << "\nNo Accounts Found!\n";
        return;
    }

    for(auto &acc : accounts)
    {
        acc.second->accountFeature();
        cout << endl;
    }
}

void BankSystem::searchAccount()
{
    int accNo;

    cout << "Enter Account Number: ";
    cin >> accNo;

    auto it = accounts.find(accNo);

    if(it != accounts.end())
    {
        it->second->accountFeature();
    }
    else
    {
        cout << "Account Not Found!\n";
    }
}
void BankSystem::depositMoney()
{
    int accNo;
    double amount;

    cout << "\n===== DEPOSIT MONEY =====\n";
    cout << "Enter Account Number: ";
    cin >> accNo;

    auto it = accounts.find(accNo);

    if(it == accounts.end())
    {
        cout << "Account Not Found!\n";
        return;
    }

    cout << "Enter Amount to Deposit: ";
    cin >> amount;

    if(amount <= 0)
    {
        cout << "Invalid Amount!\n";
        return;
    }

    BankAccount *bankAcc = dynamic_cast<BankAccount*>(it->second);

    if(bankAcc)
    {
        bankAcc->deposit(amount);

        cout << "Deposit Successful!\n";
        cout << "Current Balance: ₹" << bankAcc->getBalance() << endl;
    }
}
void BankSystem::menu()
{
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "       SMART BANKING SYSTEM\n";
        cout << "=====================================\n";
        cout << "1. Create Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Search Account\n";
        cout << "4. Deposit Money\n";
        cout << "5. Withdraw Money\n";
        cout << "6. Check Balance\n";
        cout << "7. Delete Account\n";
        cout << "8. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                displayAllAccounts();
                break;

            case 3:
                searchAccount();
                break;

            case 4:
                depositMoney();
                break;

            case 5:
                withdrawMoney();
                break;

            case 6:
                checkBalance();
                break;

            case 7:
                deleteAccount();
                break;

            case 8:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 8);
}
void BankSystem::withdrawMoney()
{
    int accNo;
    double amount;

    cout << "\n===== WITHDRAW MONEY =====\n";
    cout << "Enter Account Number: ";
    cin >> accNo;

    auto it = accounts.find(accNo);

    if(it == accounts.end())
    {
        cout << "Account Not Found!\n";
        return;
    }

    cout << "Enter Amount to Withdraw: ";
    cin >> amount;

    if(amount <= 0)
    {
        cout << "Invalid Amount!\n";
        return;
    }

    BankAccount *bankAcc = dynamic_cast<BankAccount*>(it->second);

    if(bankAcc)
    {
        bankAcc->withdraw(amount);

        cout << "Current Balance: ₹"
             << bankAcc->getBalance()
             << endl;
    }
}
void BankSystem::checkBalance()
{
    int accNo;

    cout << "\n===== CHECK BALANCE =====\n";
    cout << "Enter Account Number: ";
    cin >> accNo;

    auto it = accounts.find(accNo);

    if(it == accounts.end())
    {
        cout << "Account Not Found!\n";
        return;
    }

    BankAccount *bankAcc = dynamic_cast<BankAccount*>(it->second);

    if(bankAcc)
    {
        cout << "\nCurrent Balance: ₹"
             << bankAcc->getBalance()
             << endl;
    }
}
void BankSystem::deleteAccount()
{
    int accNo;

    cout << "\n===== DELETE ACCOUNT =====\n";
    cout << "Enter Account Number: ";
    cin >> accNo;

    auto it = accounts.find(accNo);

    if(it == accounts.end())
    {
        cout << "Account Not Found!\n";
        return;
    }

    delete it->second;
    accounts.erase(it);

    cout << "\nAccount Deleted Successfully!\n";
}
BankSystem::~BankSystem()
{
    for(auto &acc : accounts)
    {
        delete acc.second;
    }
}
void BankSystem::saveToFile()
{
}

void BankSystem::loadFromFile()
{
}