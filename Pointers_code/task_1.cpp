﻿#include <iostream> 
using namespace std;
int main()
{
    float flarr[100];       //массив чисел 
    char ch;                 //выбор пользователя 
    int num = 0;              //считает количество 
    //введенных чисел 
    do
    {
        cout << "Введите число:"; //получить числа 
        cin >> *(flarr + num++);  //пока не будет ответа 'n' 
        cout << "Продолжать(y/n)?";
        cin >> ch;
    } while (ch != 'n');
    float total = 0.0;      //сумма начинается с 0 
    for (int k = 0; k < num; k++) //прибавлять числа к сумме 
        total += *(flarr + k);
    float average = total / num;//поиск и вывод среднего 
    cout << "Среднее равно " << average << endl;
    return 0;
}