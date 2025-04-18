﻿#include <iostream> 
using namespace std;
/////////////////////////////////////////////////////////// 
class Array
{
private:
    int* ptr;          //указатель на содержимое "array"  
    int size;         //размер массива 
public:
    Array() : ptr(0), size(0) //конструктор без аргументов 
    {}
    Array(int s) :size(s)   //конструктор 
    {
        ptr = new int[s];
    }
    Array(Array&);         //конструктор копирования 
    ~Array()               //деструктор 
    {
        delete[] ptr;
    }
    int& operator [] (int j)  //перегружаемая операция 
        //нижнего индекса 
    {
        return *(ptr + j);
    }
    Array& operator =(Array&); //перегружаемый =operator 
};
//--------------------------------------------------------- 
Array::Array(Array& a)        //конструктор копирования 
{
    size = a.size;            //новый того же размера 
    ptr = new int[size];     //занять место для содержимого 
    for (int j = 0; j < size; j++)//копировать содержимое в новый массив 
        *(ptr + j) = *(a.ptr + j);
}
//--------------------------------------------------------- 
Array& Array::operator =(Array& a)//перегружаемый =operator 
{
    delete[] ptr;     //удалить старое содержимое (если было) 
    size = a.size;               //создать объект того же размера 
    ptr = new int[a.size];//занять место для нового содержимого 
    for (int j = 0; j < a.size; j++)   //копировать содержимое в объект 
        *(ptr + j) = *(a.ptr + j);
    return *this;               //вернуть этот объект 
}
/////////////////////////////////////////////////////////// 
int main()
{
    const int ASIZE = 10;     //размер массива 
    Array arr1(ASIZE);       //создать массив 
    for (int j = 0; j < ASIZE; j++) //заполнить его 
        arr1[j] = j * j;          // квадратами чисел 

    Array arr2(arr1);        //использовать конструктор 
    //копирования 
    cout << "\narr2:";
    for (int j = 0; j < ASIZE; j++)     //проверка работы с arr2 
        cout << arr2[j] << " ";
    Array arr3, arr4;         //создать два пустых массива 
    arr4 = arr3 = arr1;        //использовать операцию 
    //присваивания 
    cout << "\narr3:";
    for (int j = 0; j < ASIZE; j++)     //проверка нормальной работы с 
        //arr3 
        cout << arr3[j] << " ";
    cout << "\narr4:";
    for (int j = 0; j < ASIZE; j++)     //проверка работы с arr4 
        cout << arr4[j] << " ";
    cout << endl;
    return 0;
}