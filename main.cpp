#include <iostream>
#include "BankSystem.h"
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    BankSystem bank_system;
    string choice;

    while (true) {
        cout << "\nМеню:" << endl;
        cout << "1. Создать банк" << endl;
        cout << "2. Удалить банк" << endl;
        cout << "3.Показать банки" << endl;
        cout << "4. Создать клиента" << endl;
        cout << "5. Удалить клиента" << endl;
        cout << "6. Положить деньги" << endl;
        cout << "7. Снять деньги" << endl;
        cout << "8. Перевести деньги" << endl;
        cout << "9. Баланс банка" << endl;
        cout << "10. Баланс клиента" << endl;
        cout << "11. Выйти" << endl;

        cout << "Введите выбор: ";
        cin >> choice;

        if (choice == "1") {
            string name;
            float own_funds;
            cout << "Введите имя банка: ";
            cin >> name;
            cout << "Веведите личную сумму банка: ";
            cin >> own_funds;
            bank_system.create_bank(name, own_funds);
        } else if (choice == "2") {
            string name;
            cout << "Введите имя для удаления: ";
            cin >> name;
            bank_system.remove_bank(name);
        } else if (choice == "3") {
            bank_system.display_banks();
        } else if (choice == "4") {
            string bank_name, client_name, account_type;
            cout << "Введите имя банка чтобы добавить клиента: ";
            cin >> bank_name;
            cout << "Введите имя клиента: ";
            cin >> client_name;
            cout << "Введите тип учетной записи (individual/legal): ";
            cin >> account_type;
            bank_system.create_client(bank_name, client_name, account_type);
        } else if (choice == "5") {
            string bank_name, client_name;
            cout << "Введите название банка, чтобы удалить клиента из: ";
            cin >> bank_name;
            cout << "Введите имя клиента для удаления: ";
            cin >> client_name;
            bank_system.remove_client(bank_name, client_name);
        } else if (choice == "6") {
            string bank_name, client_name;
            float amount;
            cout << "Введите название банка: ";
            cin >> bank_name;
            cout << "Введите имя клиента: ";
            cin >> client_name;
            cout << "Введите сумму для внесения депозита: ";
            cin >> amount;
            bank_system.deposit(bank_name, client_name, amount);
        } else if (choice == "7") {
            string bank_name, client_name;
            float amount;
            cout << "Введите название банка: ";
            cin >> bank_name;
            cout << "Введите имя клиента: ";
            cin >> client_name;
            cout << "Введите сумму для вывода: ";
            cin >> amount;
            bank_system.withdraw(bank_name, client_name, amount);
        } else if (choice == "8") {
            string from_bank_name, from_client_name, to_bank_name, to_client_name;
            float amount;
            cout << "Введите название банка отправителя: ";
            cin >> from_bank_name;
            cout << "Введите имя отправителя клиента: ";
            cin >> from_client_name;
            cout << "Введите название банка получателя: ";
            cin >> to_bank_name;
            cout << "Введите имя клиента-получателя: ";
            cin >> to_client_name;
            cout << "Введите сумму для перевода: ";
            cin >> amount;
            bank_system.transfer(from_bank_name, from_client_name, to_bank_name, to_client_name, amount);
        } else if (choice == "9") {
            string bank_name;
            cout << "Введите имя банка: ";
            cin >> bank_name;
            bank_system.display_bank_balance(bank_name);
        } else if (choice == "10") {
            string bank_name, client_name;
            cout << "Введите имя банка: ";
            cin >> bank_name;
            cout << "Введите имя клиента: ";
            cin >> client_name;
            bank_system.display_client_balance(bank_name, client_name);
        } else if (choice == "11") {
            cout << "Выход..." << endl;
            break;
        } else {
            cout << "Неверный выбор. Пожалуйста, введите число от 1 до 11." << endl;
        }
    }
    return 0;
}