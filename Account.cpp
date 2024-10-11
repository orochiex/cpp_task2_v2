#include "Account.h"

Account::Account() : balance(0) {}

void Account::deposit(float amount) {
    balance += amount;
}

bool Account::withdraw(float amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

void Account::transfer(float amount, Account* recipient_account) {
    if (balance >= amount) {
        balance -= amount;
        recipient_account->deposit(amount);
    }
}

float Account::get_balance() const {
    return balance;
}