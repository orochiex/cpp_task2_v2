#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>
#include "Client.h"

class Client;

class Bank {
private:
    float own_funds;
public:
    Bank(std::string name, float own_funds);

    void add_client(Client *client);

    void remove_client(Client *client);

    void deposit(float amount);

    float get_balance() const;

    std::string name;
    std::vector<Client *> clients;
};

#endif // BANK_H