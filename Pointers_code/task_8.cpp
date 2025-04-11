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
    linklist() {
        first = NULL;
    }

    ~linklist();

    void additem(int d); 
    void display();
};

void linklist::additem(int d) {
    link* newlink = new link;
    newlink->data = d;
    newlink->next = NULL;

    if (first == NULL) {
        first = newlink;
    }
    else {
        link* current = first;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newlink;
    }
}

void linklist::display() {
    link* current = first;
    while (current != NULL) {
        cout << endl << current->data;
        current = current->next;
    }
}

linklist::~linklist() {
    link* current = first;
    while (current != NULL) {
        link* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    linklist li;
    li.additem(25);
    li.additem(36);
    li.additem(49);
    li.additem(64);
    li.display();
    cout << endl;
    return 0;
}
