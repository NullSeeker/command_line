#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Account {
public:
    string username;
    string password;
    string role;

    Account(string uname, string pwd, string r) {
        username = uname;
        password = pwd;
        role = r;
    }
};

vector<Account> accounts;

void loadAccounts() {
    ifstream file("accounts.txt");
    if (!file.is_open()) return;

    string username, password, role;
    while (file >> username >> password >> role) {
        accounts.push_back(Account(username, password, role));
    }
    file.close();
}

void saveAccounts() {
    ofstream file("accounts.txt");
    for (const auto& acc : accounts) {
        file << acc.username << " " << acc.password << " " << acc.role << endl;
    }
    file.close();
}

Account* registerAccount() {
    string username, password;
    cout << "Введите логин: ";
    cin >> username;

    for (const auto& acc : accounts) {
        if (acc.username == username) {
            cout << "❌ Ошибка: этот логин уже занят!\n";
            return nullptr;
        }
    }

    cout << "Введите пароль: ";
    cin >> password;

    accounts.push_back(Account(username, password, "user"));
    saveAccounts();

    cout << "✅ Аккаунт успешно создан!\n";
    return &accounts.back();
}

Account* login() {
    string username, password;
    cout << "Введите логин: ";
    cin >> username;
    cout << "Введите пароль: ";
    cin >> password;

    for (auto& acc : accounts) {
        if (acc.username == username && acc.password == password) {
            cout << "✅ Вход выполнен!\n";
            return &acc;
        }
    }

    cout << "❌ Ошибка: неверный логин или пароль!\n";
    return nullptr;
}

void showAccounts() {
    cout << "📜 Список всех пользователей:\n";
    for (const auto& acc : accounts) {
        cout << "👤 Логин: " << acc.username << " | Роль: " << acc.role << endl;
    }
}

void deleteUser() {
    string username;
    cout << "Введите логин пользователя для удаления: ";
    cin >> username;

    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->username == username) {
            accounts.erase(it);
            saveAccounts();
            cout << "✅ Пользователь удалён.\n";
            return;
        }
    }

    cout << "❌ Ошибка: пользователь не найден.\n";
}

void setPermission() {
    string username, newRole;
    cout << "Введите логин пользователя: ";
    cin >> username;
    cout << "Введите новую роль (user/admin): ";
    cin >> newRole;

    for (auto& acc : accounts) {
        if (acc.username == username) {
            if (newRole == "user" || newRole == "admin") {
                acc.role = newRole;
                saveAccounts();
                cout << "✅ Роль пользователя обновлена!\n";
            } else {
                cout << "❌ Ошибка: роль должна быть 'user' или 'admin'.\n";
            }
            return;
        }
    }

    cout << "❌ Ошибка: пользователь не найден.\n";
}

void showTimestamp() {
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "🕒 Текущее время: " << dt;
}

void randomNumber() {
    cout << "🎲 Случайное число: " << (rand() % 100 + 1) << endl;
}

void flipCoin() {
    cout << "🪙 Результат: " << (rand() % 2 ? "Орёл" : "Решка") << endl;
}

void joke() {
    string jokes[] = {
        "Почему программисты не боятся темноты? Потому что в темноте меньше багов!",
        "Байт укусил бит, а бит ответил: 'Ай!'",
        "Ошибка 404: Шутка не найдена!"
    };
    cout << "😂 " << jokes[rand() % 3] << endl;
}

void reverseText() {
    string text;
    cin.ignore();
    getline(cin, text);
    reverse(text.begin(), text.end());
    cout << "🔄 Перевёрнутый текст: " << text << endl;
}

void toUpperCase() {
    string text;
    cin.ignore();
    getline(cin, text);
    transform(text.begin(), text.end(), text.begin(), ::toupper);
    cout << "🔠 В верхнем регистре: " << text << endl;
}

void toLowerCase() {
    string text;
    cin.ignore();
    getline(cin, text);
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    cout << "🔡 В нижнем регистре: " << text << endl;
}

void commandLoop(Account* user) {
    bool loggedIn = true;

    while (loggedIn) {
        cout << "\n💻 Введите команду (help для списка): ";
        string command;
        cin >> command;

        if (command == "help") {
            cout << "📜 Доступные команды:\n";
            cout << "🔹 whoami — ваш логин и роль\n";
            cout << "🔹 timestamp — текущее время\n";
            cout << "🔹 random — случайное число\n";
            cout << "🔹 flip — подбрасывание монетки\n";
            cout << "🔹 joke — случайная шутка\n";
            cout << "🔹 reverse — перевернуть текст\n";
            cout << "🔹 upper — в верхний регистр\n";
            cout << "🔹 lower — в нижний регистр\n";
            cout << "🔹 exit — выйти из аккаунта\n";
            if (user->role == "admin") {
                cout << "🔹 showusers — показать всех пользователей\n";
                cout << "🔹 deluser — удалить пользователя\n";
                cout << "🔹 setperm — изменить права пользователя\n";
            }
        } else if (command == "whoami") {
            cout << "👤 Логин: " << user->username << " | Роль: " << user->role << endl;
        } else if (command == "random") randomNumber();
        else if (command == "flip") flipCoin();
        else if (command == "joke") joke();
        else if (command == "reverse") reverseText();
        else if (command == "upper") toUpperCase();
        else if (command == "lower") toLowerCase();
        else if (command == "exit") loggedIn = false;
        else cout << "❌ Неизвестная команда!\n";
    }
}

int main() {
    srand(time(0));  
    loadAccounts();

    cout << "🔹 Добро пожаловать в систему аккаунтов!\n";
    cout << "Выберите действие: login / register\n";

    string choice;
    cin >> choice;

    Account* user = nullptr;

    if (choice == "login") {
        user = login();
    } else if (choice == "register") {
        user = registerAccount();
    } else {
        cout << "❌ Неизвестная команда!\n";
        return 0;
    }

    if (user) commandLoop(user);
    return 0;
}