#include <iostream>
using namespace std;

struct link {
    int data;
    link* next;
};

class linklist {
private:
    link* first;
public:
    linklist() : first(nullptr) {}
    ~linklist();

    linklist(const linklist& other);
    linklist& operator=(const linklist& other);

    void additem(int d);
    void display();
};

linklist::~linklist() {
    link* current = first;
    while (current) {
        link* temp = current;
        current = current->next;
        delete temp;
    }
}

linklist::linklist(const linklist& other) : first(nullptr) {
    link* src = other.first;
    link** dest = &first;
    while (src) {
        *dest = new link{ src->data, nullptr };
        src = src->next;
        dest = &((*dest)->next);
    }
}

linklist& linklist::operator=(const linklist& other) {
    if (this == &other) return *this;

    this->~linklist(); 

    link* src = other.first;
    link** dest = &first;
    while (src) {
        *dest = new link{ src->data, nullptr };
        src = src->next;
        dest = &((*dest)->next);
    }
    return *this;
}

void linklist::additem(int d) {
    link* newlink = new link{ d, first };
    first = newlink;
}

void linklist::display() {
    link* current = first;
    while (current) {
        cout << current->data << ' ';
        current = current->next;
    }
    cout << endl;
}

int main() {
    linklist list1;
    list1.additem(10);
    list1.additem(20);
    list1.additem(30);

    linklist list2;
    list2 = list1;

    list1.display();
    list2.display();

    return 0;
}
