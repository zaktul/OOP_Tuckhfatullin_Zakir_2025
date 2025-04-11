﻿//метод переводит строки в верхний регистр 
#include <iostream> 
#include <cstring>      //для strcpy() и т.п. 
#include <cctype>       //для toupper() 
#include <string>

using namespace std;
/////////////////////////////////////////////////////////// 
class String            //пользовательский строковый тип 
{
private:
    char* str;         //указатель на строку 
public:
    String(char* s)    //конструктор с 1 аргументом 
    {
        int length = strlen(s);    //длина строки из аргумента 
        str = new char[length + 1]; //занять память 
        strcpy(str, s);            //скопировать туда строку 
    }
    ~String()           //деструктор 
    {
        delete str;
    }
    void display()      //вывести String 
    {
        cout << str;
    }
    void upit();        //String в верхний регистр 
};
//--------------------------------------------------------- 
void String::upit()     //каждый символ в верхний регистр 
{
char* ptrch = str;    //указатель на эту строку 
while (*ptrch)      //до пустого символа, 
  {
  *ptrch = toupper(*ptrch);//каждый символ в 
  //ВЕРХНИЙ РЕГИСТР 
ptrch++;            //перейти к следующему символу 
}
}
/////////////////////////////////////////////////////////// 
int main()
{
    String s1 = "My home is very, very beeg";
    cout << "\ns1=";     //вывести строку 
    s1.display();
    s1.upit();          //в ВЕРХНИЙ РЕГИСТР 
    cout << "\ns1=";     //вывести строку 
    s1.display();
    cout << endl;
    return 0;
}