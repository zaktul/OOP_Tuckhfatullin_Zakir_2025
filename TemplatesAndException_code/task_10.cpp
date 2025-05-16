#include <iostream>
#include <stdexcept>
#include <limits> 
using namespace std;
class Distance {
private:
    int feet;
    float inches;
public:
    Distance(int f, float i) {
        if (f < 0) {
            throw invalid_argument("Ошибка: количество футов не может быть отрицательным!");
        }
        if (i < 0 || i >= 12) {
            throw out_of_range("Ошибка: количество дюймов должно быть в диапазоне [0, 12)!");
        }
        feet = f;
        inches = i;
    }
    void getDistance() {
        cout << "Введите расстояние (футы и дюймы): ";
        try {
            if (!(cin >> feet)) {
                throw invalid_argument("Ошибка: введено некорректное значение футов!");
            }
            if (!(cin >> inches)) {
                throw invalid_argument("Ошибка: введено некорректное значение дюймов!");
            }
            if (feet < 0) {
                throw invalid_argument("Ошибка: количество футов не может быть отрицательным!");
            }
            if (inches < 0 || inches >= 12) {
                throw out_of_range("Ошибка: количество дюймов должно быть в диапазоне [0, 12)!");
            }
        }
        catch (const exception& e) {
            cout << "Исключение: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getDistance();
        }
    }
    void showDistance() const {
        cout << "Расстояние: " << feet << "'-" << inches << "\"" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    try {
        Distance d(5, 13);
    }
    catch (const exception& e) {
        cout << "Ошибка в конструкторе: " << e.what() << endl;
    }
    Distance userDist(0, 0);
    userDist.getDistance();
    userDist.showDistance();
    return 0;
}