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

int pop(Stack& S) {
    if (S.top == nullptr) {
        cout << "Stack is empty\n";
        return -1; // return -1 to indicate error
    }
    else {
        int x = S.top->data;
        if (S.top == S.head) {
            S.top = nullptr;
            S.head = nullptr;
        }
        else {
            Node* tmp = S.head;
            while (tmp->next != S.top) {
                tmp = tmp->next;
            }
            tmp->next = nullptr;
            S.top = tmp;
        }
        return x;
    }
}

bool is_empty(Stack& S) {
    return (S.top == nullptr);
}

bool is_full(Stack& S) {
    return false; // linked list-based stacks cannot be full
}

int stack_top(Stack& S) {
    if (S.top == nullptr) {
        cout << "Stack is empty\n";
        return -1; // return -1 to indicate error
    }
    else {
        return S.top->data;
    }
}

void display(Stack& S) {
    if (S.top == nullptr) {
        cout << "Stack is empty\n";
    }
    else {
        Node* current = S.head;
        cout << "Stack elements: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

int main() {
    Stack S{ nullptr, nullptr };
    push(S, 1);
    push(S, 2);
    push(S, 3);
    display(S);
    cout << "Stack top: " << stack_top(S) << endl;
    cout << "Popped element: " << pop(S) << endl;
    display(S);
    return 0;
}
