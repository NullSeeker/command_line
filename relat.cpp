// подключённые библиотеки
#include <iostream>
#include <string>
#include "func.h"

// наме спайсы
using namespace std;

// главная функция(можно и без неё)
int main()
{
    // переменные
    string aBuf;
    string aPw;
    bool keep_going;
    keep_going = false;
    bool keep_pw;
    keep_pw = true;
    
    //пару условий перед циклом
    while (keep_pw)
    {
        cout << "Введите пароль от аккаунта: ";
        cin >> aPw;
        if(aPw == "test")
        {
            keep_pw = false;
            keep_going = true;
            cout << "Вход..";
            cout << "По поводу своих паролей писать в дискорд\n";
        }
        else
        {
            cout << "Пароль не верный попробуйте снова\n";
            keep_going = false;
            keep_pw = true;
        }
        
    
    }
    
    // цикл
    while (keep_going)
    {
        /* cout вывод сообщения
        cin ввод переменной(делает переменную запоминающей)*/
        
        cout << "Введите сообщение: ";
        cin >> aBuf;

        // условие "если"(в данном случае: если переменная = слову help то выполняться код ниже.)
        if(aBuf == "помощь")
        {
            // \n перенёс на другую строку
            cout << "выход\n";
        }
        // втрое условие
        if (aBuf == "help")
        {
            cout << "выход\n";
        }
    
        if(aBuf == "выход")
        {
            keep_going = false;
        }
    
        if(aBuf != "выход")
        {
            cout << "Сообщение отправлено!\n";
        }
    }

}