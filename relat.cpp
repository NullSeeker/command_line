// подключённые библиотеки
#include <iostream>
#include <string>

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


    // вывод перед циклом
    cout << "Если у вас нету аккаунта то ввелите команду 'регистрация'\n";
    
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


        if(aPw == "pupsik")
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
        
        if(aPw == "выход")
        {
            keep_pw = false;
            keep_going = false;
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
        if(aBuf == "помощь")
        {
            // \n перенёс на другую строку
            cout << "Команды: выход, дискорд, регистрация.\n";
        }
        
        if(aBuf == "выход")
        {
            keep_going = false;
        }
    
        if(aBuf != "выход")
        {
            cout << "Сообщение отправлено!\n";
        }
    
        if(aBuf == "регистрация")
        {
            cout << "Для регистрации напишите дискорд\n";
        }

        if(aBuf == "дискорд")
        {
            cout << "ChillWood#5180\n";
        }    
    
    }
}