#include "Client.h"

using namespace std;

Client::Client(std::string name, std::string account_type) : name(name), account_type(account_type) {}

void Client::deposit(float amount) {
    account.deposit(amount);
}

bool Client::withdraw(float amount) {
    return account.withdraw(amount);
}

void Client::transfer(float amount, Account* recipient_account) {
    account.transfer(amount, recipient_account);
}

float Client::get_balance() const {
    return account.get_balance();
}