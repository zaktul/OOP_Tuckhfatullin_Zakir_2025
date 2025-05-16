#include <iostream>
using namespace std;
template <typename mlk>
struct node {
    mlk value;
    node* next;
};
template <typename mlk>
node<mlk>* postroenie(node<mlk>*& ko) {
    cout << "Вводите элементы очереди (введите 0 для завершения): " << endl;
    mlk val;
    node<mlk>* no = nullptr;
    cin >> val;
    while (val != 0) {
        node<mlk>* t = new node<mlk>;
        t->value = val;
        t->next = nullptr;
        if (no == 0) {
            no = ko = t;
        }
        else {
            ko->next = t;
            ko = t;
        }
        cin >> val;
    }
    cout << "Очередь построена" << endl;
    return no;
}
template <typename mlk>
void print(node<mlk>* no) {
    node<mlk>* r = no;
    cout << "Начало очереди" << endl;
    while (r != 0) {
        cout << "\t" << r->value << "\n";
        r = r->next;
    }
    cout << "Конец очереди!" << endl;
}
int main() {
    setlocale(LC_ALL, "rus");
    node<int>* into = nullptr;
    node<double>* doubleo = nullptr;
    node<long>* longo = nullptr;

    cout << "Создание очереди int: " << endl;
    into = postroenie(into);
    print(into);

    cout << "Создание очереди double:" << endl;
    doubleo = postroenie(doubleo);
    print(doubleo);

    cout << "Создание очереди char:" << endl;
    longo = postroenie(longo);
    print(longo);

    return 0;
}