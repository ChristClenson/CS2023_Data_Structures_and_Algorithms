#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* head;
    Node* top;
};

void push(Stack& S, int n) {
    Node* new_node = new Node{ n, nullptr };
    if (S.head == nullptr) {
        S.head = new_node;
        S.top = new_node;
    }
    else {
        S.top->next = new_node;
        S.top = new_node;
    }
}

int stack_top(Stack& S) {
    if (S.top == nullptr) {
        cerr << "Error: Stack is empty\n";
        exit(1);
    }
    return S.top->data;
}

int main() {
    Stack S{ nullptr, nullptr };
    push(S, 1);
    push(S, 2);
    push(S, 3);
    cout << "Top element: " << stack_top(S) << endl;
    return 0;
}
