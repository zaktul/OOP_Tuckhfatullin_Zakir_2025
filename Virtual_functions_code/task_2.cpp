﻿//дружественная функция square() для Distance 
#include <iostream> 
using namespace std;
/////////////////////////////////////////////////////////// 
class Distance          //класс английских расстояний 
{
private:
    int feet;
    float inches;
public:
    Distance()        //конструктор без аргументов 
    {
        feet = 0; inches = 0.0;
    }
    Distance(float fltfeet) //конструктор с одним аргументом 
    {                     //футы — целая часть 
        feet = static_cast<int>(fltfeet);
        inches = 12 * (fltfeet - feet);//дюймы – в остатке 
    }
    //конструктор с двумя аргументами 
    Distance(int ft, float in) :feet(ft), inches(in)
    {}
    void showdist()   //вывод расстояния 
    {
        cout << feet << "\'-" << inches << '\"';
    }
    //дружественная 
    friend Distance operator *(Distance, Distance);
};
//--------------------------------------------------------- 
//умножить d1 на d2 
Distance operator *(Distance d1, Distance d2)
{
    float fltfeet1 = d1.feet + d1.inches / 12; //преобразовать в float 
    float fltfeet2 = d2.feet + d2.inches / 12;
    float multfeet = fltfeet1 * fltfeet2;    //найти результат 
    return Distance(multfeet);        //вернуть временное значение 
}
/////////////////////////////////////////////////////////// 
int main()
{
    Distance dist1(3, 6.0);  //создать какие-то расстояния 
    Distance dist2(2, 3.0);
    Distance dist3;
    dist3 = dist1 * dist2;    //умножение 
        dist3 = 10.0 * dist3;     //умножение и преобразование 
    //вывести все расстояния 
    cout << "\ndist1 ="; dist1.showdist();
    cout << "\ndist2 ="; dist2.showdist();
    cout << "\ndist3 ="; dist3.showdist();
    cout << endl;
    return 0;
}