#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include <vector>
#include <string>

class Bank;
class Client;

class BankSystem {
private:
    std::vector<Bank *> banks;
public:
    void create_bank(std::string name, float own_funds);

    void remove_bank(std::string name);

    void display_banks();

    void create_client(std::string bank_name, std::string client_name, std::string account_type);

    void remove_client(std::string bank_name, std::string client_name);

    void deposit(std::string bank_name, std::string client_name, float amount);

    void withdraw(std::string bank_name, std::string client_name, float amount);

    void transfer(std::string from_bank_name, std::string from_client_name, std::string to_bank_name,
                  std::string to_client_name, float amount);

    void display_client_balance(std::string bank_name, std::string client_name);

    void display_bank_balance(std::string bank_name);

    void deposit_to_bank(std::string bank_name, float amount);
};

#endif // BANKSYSTEM_H