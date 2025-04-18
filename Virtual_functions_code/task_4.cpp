﻿#include <iostream> 
using namespace std;
/////////////////////////////////////////////////////////// 
class Array
{
    //моделирует обычный массив C++  
private:
    int* ptr;                //указатель на содержимое Array 
    int size;                //размер Array 
public:
    Array(int s)             //конструктор с одним аргументом 
    {
        size = s;              //аргумент – размер Array  
        ptr = new int[s];      //выделить память под Array  
    }
    ~Array()                 //деструктор 
    {
        delete[] ptr;
    }
    int& operator [] (int j) //перегружаемая операция 
        //списка индексов 
    {
        return *(ptr + j);
    }
};
/////////////////////////////////////////////////////////// 
int main()
{
    const int ASIZE = 10;      //размер массива 
    Array arr(ASIZE);          //создать массив 

    for (int j = 0; j < ASIZE; j++) //заполнить его j^2 
        arr[j] = j * j;

    for (int j = 0; j < ASIZE; j++)     //вывести его содержимое 
        cout << arr[j] << ' ';
    cout << endl;
    return 0;
}