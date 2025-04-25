﻿#include <fstream>               //для файловых функций 
#include <iostream> 
using namespace std;
#include <process.h>             //для exit() 
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");
    if (argc != 3)
    {
        cerr << "\nФормат:ocopy srcfile destfile "; exit(-1);
    }
    char ch;                 //символ для считывания 
    ifstream infile;         //создать входной файл 
    infile.open(argv[1]); //открыть файл 
    if (!infile)             //проверка на ошибки 
    {
        cerr << "\nНевозможно открытие " << argv[1]; exit(-1);
    }
    ofstream outfile;        //создать выходной файл 
    outfile.open(argv[2]);//открыть его 
    if (!outfile)            //проверка на ошибки 
    {
        cerr << "\nНевозможно открытие " << argv[2]; exit(-1);
    }
    while (infile)           //до EOF 
    {
        infile.get(ch);      //считать символ 
        outfile.put(ch);     //записать символ 
    }
    return 0;
}