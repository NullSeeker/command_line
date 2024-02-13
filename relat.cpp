// подключённые библиотеки
#include <iostream>
#include <string>

// наме спайсы
using namespace std;

class CRegister {

public:
    bool m_Register;
    void Register();
    string m_Accounts;

private:
      string m_Password;
};

CRegister m_AccountData;


// главная функция(можно и без неё)
int main()
{

    // переменные
    string aReg;
    string aBuf;
    string aPw;
    bool keep_going;
    keep_going = false;
    bool keep_pw;
    keep_pw = true;
    m_AccountData.m_Register = false;

    // вывод перед циклом
    cout << "Если у вас нету аккаунта то введите команду 'reg'\n";

    while (keep_pw)
    {
        cout << "Введите пароль от аккаунта: ";
        cin >> aPw;

        // пароль


        if(aPw == "test")
        {
            keep_pw = false;
            keep_going = true;
            cout << "Вход..\n";
            cout << "По поводу своих паролей писать в дискорд\n";
        }
        else
        {
            cout << "Пароль не верный попробуйте снова\n";
            keep_going = false;
            keep_pw = true;

        }

        if(aPw ==m_AccountData.m_Accounts)
        {
          keep_pw = false;
          keep_going = true;
          cout << "Вход..\n";
          cout << "По поводу своих паролей писать в дискорд\n";
        }



        if(aPw == "tust")
        {
            keep_pw = false;
            keep_going = true;
            cout << "Вход..\n";
            cout << "По поводу своих паролей писать в дискорд\n";
        }



        if(aPw == "exit")
        {
            keep_pw = false;
        }

        if (aPw == "reg") {

            m_AccountData.m_Register = true;
            keep_pw = false;
        }

        while (m_AccountData.m_Register) {

            cout << "Добро пожаловать в регестрацию\n";
            cout << "Введите новый пароль: ";
            cin >> aReg;

            m_AccountData.m_Accounts = aReg;

            cout << "Спасибо за регестрацию, нажмите 'н' что бы выйти\n";

            keep_pw = true;
            m_AccountData.m_Register = false;
            break;

        }

    }



    // цикл
    while (keep_going)
    {
        /* cout вывод сообщения
        cin ввод переменной(делает переменную запоминающей)*/

        cout << "Введите сообщение: ";
        cin >> aBuf;

        // условие "если"(в данном случае: если переменная = слову  то выполняться код ниже.)
        if(aBuf == "help")
        {
            // \n перенёс на другую строку
            cout << "Команды: exit, discord, reg( in lo.\n";
        }

        if(aBuf == "exit")
        {
            keep_going = false;
        }

        if(aBuf == "reg")
        {
            cout << "Регистрация: при входе нужно ввести слово \n";
        }

        if(aBuf == "discrod")
        {
            cout << "saintphnx.";
        }

    }
}
