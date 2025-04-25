﻿//записывает массив 
#include <iostream> 
#include <fstream>        //для файловых потоков 
using namespace std;
/////////////////////////////////////////////////////////// 
class Distance            //класс английских расстояний 
{
private:
    int feet;
    float inches;
public:
    Distance() :feet(0), inches(0.0)//конструктор без аргументов 
    {}
    //конструктор с двумя аргументами 
    Distance(int ft, float in) :feet(ft), inches(in)
    {}
    void getdist()//получить расстояние от пользователя 
    {
        cout << "\nВведите футы:"; cin >> feet;
        cout << "Введите дюймы:"; cin >> inches;
    }
    void showdist()               //вывести расстояние 
    {
        cout << feet << "\'-" << inches << '\"';
    }
};
/////////////////////////////////////////////////////////// 
int main()
{
    setlocale(LC_ALL, "rus");
    char ch;
    Distance dist;    //создать объект Distance 
    fstream file;     //создать входной/выходной файл 
    //открыть его для добавления 
    file.open("DIST.DAT ", ios::binary | ios::app |
        ios::out | ios::in);
    do                //данные от пользователя в файл 
    {
        cout << "\nРасстояние ";
        dist.getdist();//получить расстояние 
        //записать в файл 
        file.write((char*)&dist, sizeof(dist));
        cout << "Продолжать (y/n)?";
        cin >> ch;
    }
    while (ch == 'y');  //выйти по 'n' 
    file.seekg(0);    //установить указатель на начало 
    //файла 
    //прочитать первое значение 
    file.read((char*)&dist, sizeof(dist));
    int count = 0;
    while (!file.eof())//выход по EOF 
    {
        cout << "\nРасстояние " << ++count << ":";//вывести 
        //расстояние 
        dist.showdist();
        file.read((char*)&dist, sizeof(dist)); //считать еще 
        //расстояние 
    }
    cout << endl;
    return 0;
}