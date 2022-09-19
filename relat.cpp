//библиотеки
#include <iostream>
#include <string>

// наме спайсы
using namespace std;

// главная функция(можно и без неё)
int main()
{
    // переменные
    string aBuf;
    char Foo;
    bool keep_going;
    keep_going = true;

    // цикл
    while (keep_going)
    {
        /* cout вывод сообщения
        cin ввод переменной(делает переменную запоминающей)*/
        
        cout << "Введите сообщение: ";
        cin >> aBuf;

        // условие "если"(в данном случае: если переменная = слову help то выполняеься код ниже.)
        if(aBuf == "помощь")
        {
            // \n перенёс на другую строку
            cout << "выход(exit)\n";
        }
        // втрое условие
        if (aBuf == "help")
        {
            cout << "выход(exit)\n";
        }
        
        if(aBuf == "exit")
        {
            keep_going = false;
        }
    
        if(aBuf == "выход")
        {
            keep_going = false;
        }
    }
    
    
}