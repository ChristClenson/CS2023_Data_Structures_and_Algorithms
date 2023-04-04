#include <iostream>
using namespace std;

const int MAXSIZE = 5;

class Stack {
private:
    int top;
    int stack[MAXSIZE];

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAXSIZE - 1);
    }

    void push(int item) {
        if (isFull()) {
            cout << "Error: Stack Overflow\n";
        }
        else {
            top++;
            stack[top] = item;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Error: Stack Underflow\n";
            return -1;
        }
        else {
            int item = stack[top];
            top--;
            return item;
        }
    }

    int stackTop() {
        if (isEmpty()) {
            cout << "Error: Stack is empty\n";
            return -1;
        }
        else {
            return stack[top];
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
        }
        else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << stack[i] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Stack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    myStack.display(); // Stack elements: 5 4 3 2 1

    cout << "Stack top: " << myStack.stackTop() << "\n"; // Stack top: 5

    myStack.pop();

    myStack.display(); // Stack elements: 4 3 2 1

    cout << "Stack top: " << myStack.stackTop() << "\n"; // Stack top: 4

    return 0;
}
