#include <iostream>
#include <fstream>
using namespace std;

struct Link {
    int data;
    Link* next;
};

class LinkList {
private:
    Link* first;
public:
    LinkList() : first(nullptr) {}

    void additem(int d) {
        Link* newlink = new Link{ d, first };
        first = newlink;
    }

    void display() {
        Link* curr = first;
        while (curr) {
            cout << curr->data << ' ';
            curr = curr->next;
        }
        cout << endl;
    }

    void write_to_file() {
        ofstream out("linklist.dat");
        Link* curr = first;
        while (curr) {
            out << curr->data << '\n';
            curr = curr->next;
        }
        out.close();
    }

    void read_from_file() {
        ifstream in("linklist.dat");
        int d;
        while (in >> d) {
            additem(d);
        }
        in.close();
    }
};

int main() {
    LinkList list;
    char option;
    do {
        cout << "\nMenu:\n1. Add\n2. Display\n3. Save to file\n4. Load from file\nChoose: ";
        cin >> option;
        if (option == '1') {
            int val;
            cout << "Enter number: "; cin >> val;
            list.additem(val);
        }
        else if (option == '2') {
            list.display();
        }
        else if (option == '3') {
            list.write_to_file();
        }
        else if (option == '4') {
            list = LinkList();
            list.read_from_file();
        }
    } while (option != 'q');
    return 0;
}
