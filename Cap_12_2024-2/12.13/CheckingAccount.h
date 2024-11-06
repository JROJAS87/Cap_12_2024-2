#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
public:
    CheckingAccount(double balance, double feePerTransaction)
        : Account(balance), feePerTransaction(feePerTransaction) {}

    bool debit(double amount) override {
        if (Account::debit(amount)) {
            balance -= feePerTransaction; // Deduce la tarifa de transacción
            return true;
        }
        return false;
    }

private:
    double feePerTransaction;
};

#endif