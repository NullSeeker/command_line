#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

class Account {
public:
    string username;
    string password;
    string role; // user или admin

    Account(string uname, string pwd, string r) {
        username = uname;
        password = pwd;
        role = r;
    }
};

vector<Account> accounts;

// Загрузка аккаунтов из файла
void loadAccounts() {
    ifstream file("accounts.txt");
    if (!file.is_open()) return;

    string username, password, role;
    while (file >> username >> password >> role) {
        accounts.push_back(Account(username, password, role));
    }
    file.close();
}

// Сохранение аккаунтов в файл
void saveAccounts() {
    ofstream file("accounts.txt");
    for (const auto& acc : accounts) {
        file << acc.username << " " << acc.password << " " << acc.role << endl;
    }
    file.close();
}

// Регистрация аккаунта
Account* registerAccount() {
    string username, password;
    cout << "Введите логин: ";
    cin >> username;

    // Проверка, существует ли аккаунт
    for (const auto& acc : accounts) {
        if (acc.username == username) {
            cout << "Ошибка: этот логин уже занят!\n";
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

// Вход в систему
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

// Показать всех пользователей (для админов)
void showAccounts() {
    cout << "📜 Список всех пользователей:\n";
    for (const auto& acc : accounts) {
        cout << "👤 Логин: " << acc.username << " | Роль: " << acc.role << endl;
    }
}

// Удаление пользователя (для админов)
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

// Изменение роли пользователя (для админов)
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

// Смена пароля
void changePassword(Account* user) {
    string newPassword;
    cout << "Введите новый пароль: ";
    cin >> newPassword;

    user->password = newPassword;
    saveAccounts();
    cout << "✅ Пароль успешно изменён!\n";
}

// Вывод текущего времени
void showTimestamp() {
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "🕒 Текущее время: " << dt;
}

// Очистка экрана (работает только на Windows)
void clearScreen() {
    system("cls");
}

// Цикл команд после входа
void commandLoop(Account* user) {
    bool loggedIn = true;

    while (loggedIn) {
        cout << "\n💻 Введите команду (help для списка): ";
        string command;
        cin >> command;

        if (command == "help") {
            cout << "📜 Доступные команды:\n";
            cout << "🔹 help — список команд\n";
            cout << "🔹 status — информация о вашем аккаунте\n";
            cout << "🔹 changepw — сменить пароль\n";
            cout << "🔹 echo <текст> — повторить текст\n";
            cout << "🔹 timestamp — текущее время\n";
            cout << "🔹 clear — очистить экран (только Windows)\n";
            cout << "🔹 exit — выйти из аккаунта\n";
            if (user->role == "admin") {
                cout << "🔹 showusers — показать всех пользователей\n";
                cout << "🔹 deluser — удалить пользователя\n";
                cout << "🔹 setperm — изменить права пользователя\n";
            }
        } else if (command == "status") {
            cout << "👤 Логин: " << user->username << "\n";
            cout << "🛠 Роль: " << user->role << "\n";
        } else if (command == "changepw") {
            changePassword(user);
        } else if (command == "echo") {
            string message;
            getline(cin >> ws, message);
            cout << "📢 " << message << endl;
        } else if (command == "timestamp") {
            showTimestamp();
        } else if (command == "clear") {
            clearScreen();
        } else if (command == "exit") {
            loggedIn = false;
            cout << "🚪 Выход...\n";
        } else if (command == "showusers" && user->role == "admin") {
            showAccounts();
        } else if (command == "deluser" && user->role == "admin") {
            deleteUser();
        } else if (command == "setperm" && user->role == "admin") {
            setPermission();
        } else {
            cout << "❌ Неизвестная команда!\n";
        }
    }
}

int main() {
    loadAccounts();

    while (true) {
        cout << "\n🔹 1. Вход\n🔹 2. Регистрация\n🔹 3. Выход\n➡ Выбор: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            Account* user = login();
            if (user) commandLoop(user);
        } else if (choice == 2) {
            Account* newUser = registerAccount();
            if (newUser) commandLoop(newUser);
        } else if (choice == 3) {
            cout << "👋 До свидания!\n";
            break;
        } else {
            cout << "❌ Ошибка: неверный ввод!\n";
        }
    }

    return 0;
}