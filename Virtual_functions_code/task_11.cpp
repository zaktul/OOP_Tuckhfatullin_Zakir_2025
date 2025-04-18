#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

// Базовый абстрактный класс
class Token {
public:
    virtual float getNumber() = 0;
    virtual char getOperator() = 0;
    virtual ~Token() {}
};

// Класс числа
class Number : public Token {
private:
    float fnum;
public:
    Number(float f) : fnum(f) {}
    float getNumber() override { return fnum; }
    char getOperator() override { return ' '; }
};

// Класс оператора
class Operator : public Token {
private:
    char op;
public:
    Operator(char o) : op(o) {}
    float getNumber() override { return 0.0f; }
    char getOperator() override { return op; }
};

// Стек, содержащий указатели на Token
class Stack {
private:
    Token* arr[100];
    int top;
public:
    Stack() : top(0) {}
    void push(Token* ptr) {
        arr[top++] = ptr;
    }
    Token* pop() {
        return arr[--top];
    }
    int size() const {
        return top;
    }
};

float evaluate(Stack& stack) {
    Token* t1 = nullptr;
    Token* t2 = nullptr;
    Token* tOp = nullptr;

    while (stack.size() > 1) {
        t1 = stack.pop();
        tOp = stack.pop();
        t2 = stack.pop();

        float num1 = t2->getNumber();
        float num2 = t1->getNumber();
        char op = tOp->getOperator();

        float result = 0.0f;
        switch (op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': result = num1 / num2; break;
        default:
            cout << "Unknown operator: " << op << endl;
            exit(1);
        }

        delete t1;
        delete t2;
        delete tOp;

        stack.push(new Number(result));
    }

    float finalResult = stack.pop()->getNumber();
    return finalResult;
}

int main() {
    char input[100];
    char choice;

    do {
        cout << "Enter expression (e.g. 3.5+2.1*4): ";
        cin >> input;

        Stack s;
        int i = 0;
        while (input[i]) {
            if (isdigit(input[i]) || input[i] == '.') {
                char numberStr[32];
                int j = 0;
                while (isdigit(input[i]) || input[i] == '.')
                    numberStr[j++] = input[i++];
                numberStr[j] = '\0';
                float value = atof(numberStr);
                s.push(new Number(value));
            }
            else if (strchr("+-*/", input[i])) {
                s.push(new Operator(input[i]));
                i++;
            }
            else {
                cout << "Invalid character: " << input[i] << endl;
                exit(1);
            }
        }

        float result = evaluate(s);
        cout << "Result: " << result << endl;

        cout << "Evaluate another expression? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
