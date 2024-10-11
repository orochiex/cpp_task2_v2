#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
private:
    float balance;
public:
    Account();
    void deposit(float amount);
    bool withdraw(float amount);
    void transfer(float amount, Account* recipient_account);
    float get_balance() const;
};

#endif // ACCOUNT_H