﻿#include <fstream>               //для файловых функций 
#include <iostream> 
using namespace std;
#include <process.h>             //для exit() 
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");
    if (argc != 2)
    {
        cerr << "\nФормат:filename \n "; exit(-1);
    }
    ifstream infile;         //создать входной файл 
    infile.open(argv[1]); //и открыть его 
    if (!infile)             //проверка наличия ошибок 
    {
        cerr << "\nНевозможно открытие" << argv[1]; exit(-1);
    }
    infile.seekg(0, ios::end);//перейти на конец файла 
    //сообщить номер байта 
    cout << "Размер " << argv[1] << " равен "
        << infile.tellg();
    cout << endl;
    return 0;
}