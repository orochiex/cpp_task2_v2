#include "BankSystem.h"
#include "Bank.h"
#include "Client.h"
#include <algorithm>
#include "iostream"

using namespace std;

void BankSystem::create_bank(string name, float own_funds) {
    banks.push_back(new Bank(name, own_funds));
}

void BankSystem::remove_bank(string name) {
    auto it = find_if(banks.begin(), banks.end(), [&](Bank *bank) { return bank->name == name; });
    if (it != banks.end()) {
        banks.erase(it);
        delete *it;
    }
}

void BankSystem::display_banks() {
    cout << "Доступные банки:" << endl;
    for (auto bank: banks) {
        cout << "- " << bank->name << endl;
    }
}

void BankSystem::create_client(string bank_name, string client_name, string account_type) {
    for (auto bank: banks) {
        if (bank->name == bank_name) {
            bank->add_client(new Client(client_name, account_type));
            cout << "Клиент '" << client_name << "' добавлен в банк '" << bank_name << "'." << endl;
            return;
        }
    }
    cout << "Банк '" << bank_name << "' не найден." << endl;
}

void BankSystem::remove_client(string bank_name, string client_name) {
    for (auto bank: banks) {
        if (bank->name == bank_name) {
            bank->remove_client(new Client(client_name, ""));
            cout << "Клиент '" << client_name << "' удален из банка '" << bank_name << "'." << endl;
            return;
        }
    }
    cout << "Банк '" << bank_name << "' не найден." << endl;
}

void BankSystem::deposit(string bank_name, string client_name, float amount) {
    for (auto bank: banks) {
        if (bank->name == bank_name) {
            for (auto client: bank->clients) {
                if (client->name == client_name) {
                    client->deposit(amount);
                    cout << "Внесено " << amount << " клиенту '" << client_name << "' в банк '"
                         << bank_name << "'." << endl;
                    return;
                }
            }
            cout << "Клиент '" << client_name << "' не найден в банке '" << bank_name << "'." << endl;
            return;
        }
    }
    cout << "Банк '" << bank_name << "' не найден." << endl;
}

void BankSystem::withdraw(string bank_name, string client_name, float amount) {
    for (auto bank: banks) {
        if (bank->name == bank_name) {
            for (auto client: bank->clients) {
                if (client->name == client_name) {
                    if (client->withdraw(amount)) {
                        cout << "Снято " << amount << " с клиента '" << client_name << "' в банке '"
                             << bank_name << "'." << endl;
                    } else {
                        cout << "Недостаточно средств для клиента '" << client_name << "' в банке '" << bank_name
                             << "'." << endl;
                    }
                    return;
                }
            }
            cout << "Клиент '" << client_name << "' не найден в банке '" << bank_name << "'." << endl;
            return;
        }
    }
    cout << "Банк '" << bank_name << "' не найден." << endl;
}

void BankSystem::transfer(string from_bank_name, string from_client_name, string to_bank_name,
                          string to_client_name, float amount) {
    Bank *from_bank = nullptr;
    Bank *to_bank = nullptr;
    Client *from_client = nullptr;
    Client *to_client = nullptr;

    for (auto bank: banks) {
        if (bank->name == from_bank_name) {
            from_bank = bank;
            for (auto client: bank->clients) {
                if (client->name == from_client_name) {
                    from_client = client;
                    break;
                }
            }
            break;
        }
    }
    for (auto bank: banks) {
        if (bank->name == to_bank_name) {
            to_bank = bank;
            for (auto client: bank->clients) {
                if (client->name == to_client_name) {
                    to_client = client;
                    break;
                }
            }
            break;
        }
    }
    if (!from_bank || !to_bank || !from_client || !to_client) {
        cout << "Один или несколько банков/клиентов не найдены." << endl;
        return;
    }
    if (!from_client->withdraw(amount)) {
        cout << "Недостаточно средств для клиента '" << from_client_name << "' в банке '" << from_bank_name
             << "'." << endl;
        return;
    }
    float commision = amount * 0.05;
    from_client ->withdraw(commision);
    from_bank->deposit(commision);

    to_client->deposit(amount - commision);

    cout << "Передано " << amount << " от клиента '" << from_client_name << "' в банк '"
         << from_bank_name << "' клиенту '" << to_client_name << "' в банк '" << to_bank_name << "'."
         << endl;
}

void BankSystem::display_bank_balance(string bank_name) {
    for (auto bank: banks) {
        if (bank->name == bank_name) {
            cout << "Банк '" << bank_name << "' баланс: " << bank->get_balance() << endl;
            return;
        }
    }
    cout << "Банк '" << bank_name << "' не найден." << endl;
}

void BankSystem::display_client_balance(string bank_name, string client_name) {
    for (auto bank: banks) {
        if (bank->name == bank_name) {
            for (auto client: bank->clients) {
                if (client->name == client_name) {
                    cout << "Клиент '" << client_name << "' баланс в банке '" << bank_name << "': " << client->get_balance() << endl;
                    return;
                }
            }
            cout << "Клиент '" << client_name << "' не найден в банке '" << bank_name << "'." << endl;
            return;
        }
    }
    cout << "Банк '" << bank_name << "' не найцден." << endl;
}

void BankSystem::deposit_to_bank(string bank_name, float amount) {
    for (auto bank : banks) {
        if (bank->name == bank_name) {
            bank->deposit(amount);
            cout << "Положено " << amount << " в банк '" << bank_name << "'." << endl;
            return;
        }
    }
    cout << "Банк '" << bank_name << "' не найден." << endl;
}
