#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Account.h"

class Account;

class Client {
private:
    std::string account_type;
    Account account;
public:
    Client(std::string name, std::string account_type);
    void deposit(float amount);
    bool withdraw(float amount);
    void transfer(float amount, Account* recipient_account);
    float get_balance() const;

    std::string name;
};

#endif // CLIENT_H