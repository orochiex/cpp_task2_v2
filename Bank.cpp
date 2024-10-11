#include "Bank.h"
#include <algorithm>

Bank::Bank(std::string name, float own_funds) : name(name), own_funds(own_funds) {}

void Bank::add_client(Client* client) {
    clients.push_back(client);
}

void Bank::remove_client(Client* client) {
    auto it = std::find(clients.begin(), clients.end(), client);
    if (it != clients.end()) {
        clients.erase(it);
    }
}

float Bank::get_balance() const {
    return own_funds;
}

void Bank::deposit(float amount) {
    own_funds += amount;
}