//класс публикаций и порожденные 
#include <iostream> 
#include <string> 
using namespace std;
/////////////////////////////////////////////////////////// 
class publication
{
private:
    string title;
    float price;
public:
    virtual void getdata()
    {
        cout << "\nInput title: "; cin >> title;
        cout << "Input price: "; cin >> price;
    }
    virtual void putdata()
    {
        cout << "\n \nTitle: " << title;
        cout << "\nPrice: " << price;
    }
};
/////////////////////////////////////////////////////////// 
class book : public publication
{
private:
    int pages;
public:
    void getdata()
    {
        publication::getdata();
        cout << "Input number of pages: "; cin >> pages;
        isOveersize();
    }
    void putdata()
    {
        publication::putdata();
        cout << "\nPages: " << pages;
    }
    void isOveersize() {
        if (pages > 800) { cout << "Size out of the range!" << endl; }
    }
};
/////////////////////////////////////////////////////////// 
class tape :public publication
{
private:
    float time;
public:
    void getdata()
    {
        publication::getdata();
        cout << "Input sounding time: "; cin >> time;
        isOveersize();
    }
    void putdata()
    {
        publication::putdata();
        cout << "\nSounding time: " << time;
    }
    void isOveersize() {
        if (time > 90) { cout << "Size out of the range!" << endl; }
    }
};
/////////////////////////////////////////////////////////// 
int main()
{
    publication* pubarr[100]; //массив указателей на 
    // публикации 
    int n = 0;                 //число публикаций в массиве 
    char choice;              //выбор пользователя 
    do {
        cout << "\nInput data for book of film (b/t)?";
        cin >> choice;
        if (choice == 'b')       //создать объект «книга» 
            pubarr[n] = new book; //занести в массив 
        else                     //создать объект «пленка» 
            pubarr[n] = new tape;     //занести в массив 
        pubarr[n++]->getdata();   //получить данные об объекте 
        cout << "Continue (y/n)?";//еще публикации? 
        cin >> choice;
    } while (choice == 'y');       //цикл, пока не будет ответ 'y' 
    for (int j = 0; j < n; j++)        //цикл по всем объектам 
        pubarr[j]->putdata();      //вывести данные о публикации 
    cout << endl;
    return 0;
}