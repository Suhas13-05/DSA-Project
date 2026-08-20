#ifndef CURRENT_H
#define CURRENT_H

#include "BankAccount.h"

class Current : public BankAccount
{
private:
    double overdraftLimit;

public:
    Current();
    Current(int accNo, string name, string phone,
            double bal, double limit);

    void accountFeature() override;

    ~Current();
};

#endif