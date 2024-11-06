#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
public:
    SavingsAccount(double balance, double interestRate)
        : Account(balance), interestRate(interestRate) {}

    double calculateInterest() const {
        return balance * interestRate;
    }

private:
    double interestRate;
};

#endif