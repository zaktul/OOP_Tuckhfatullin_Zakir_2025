#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;

class Token {
public:
    virtual float getNumber() = 0;
    virtual char getOperator() = 0;
    virtual ~Token() {}
};

class Operator : public Token {
private:
    char oper;
public:
    Operator(char op) : oper(op) {}
    float getNumber() { return 0.0f; } 
    char getOperator() { return oper; }
};

class Number : public Token {
private:
    float fnum;
public:
    Number(float val) : fnum(val) {}
    float getNumber() { return fnum; }
    char getOperator() { return ' '; } 
};

class Stack {
private:
    Token* data[100];
    int top = 0;
public:
    void push(Token* t) { data[top++] = t; }
    Token* pop() { return data[--top]; }
    int size() const { return top; }
};

int main() {
    char expr[100];
    char choice;
    do {
        cout << "Enter float expression (e.g. 3.14/2.0+5*3): ";
        cin >> expr;

        Stack s;
        int len = strlen(expr);
        for (int i = 0; i < len;) {
            if (isdigit(expr[i]) || expr[i] == '.') {
                char num[32];
                int j = 0;
                while (isdigit(expr[i]) || expr[i] == '.')
                    num[j++] = expr[i++];
                num[j] = '\0';
                s.push(new Number(atof(num)));
            }
            else if (strchr("+-*/", expr[i])) {
                s.push(new Operator(expr[i++]));
            }
            else {
                cout << "Invalid character in input.\n";
                exit(1);
            }
        }

        vector<float> numbers;
        vector<char> ops;

        while (s.size() > 0) {
            Token* t = s.pop();
            if (t->getOperator() == ' ')
                numbers.push_back(t->getNumber());
            else
                ops.push_back(t->getOperator());
            delete t;
        }

        while (!ops.empty()) {
            float a = numbers.back(); numbers.pop_back();
            float b = numbers.back(); numbers.pop_back();
            char op = ops.back(); ops.pop_back();

            float result;
            switch (op) {
            case '+': result = a + b; break;
            case '-': result = b - a; break;
            case '*': result = a * b; break;
            case '/': result = b / a; break;
            default: cout << "Unknown operator\n"; return 1;
            }
            numbers.push_back(result);
        }

        cout << "Result: " << numbers.back() << endl;

        cout << "Try another expression? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
