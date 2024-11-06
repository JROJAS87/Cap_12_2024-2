#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
    explicit Account(double balance) : balance(balance >= 0 ? balance : 0) {}

    virtual void credit(double amount) {
        if (amount > 0) balance += amount;
    }

    virtual bool debit(double amount) {
        if (amount > balance) {
            return false;
        } else {
            balance -= amount;
            return true;
        }
    }

    double getBalance() const {
        return balance;
    }

    virtual ~Account() = default; // Destructor virtual para comportamiento polimórfico

protected:
    double balance;
};

#endif