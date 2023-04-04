#include <iostream>
#include <climits>
using namespace std;

int stack_top(int stack[], int top) {
    if (top == -1) {
        // Stack is empty, return error value
        return INT_MIN;
    }
    else {
        // Return top element of stack
        return stack[top];
    }
}

int main() {
    const int SIZE = 5;
    int stack[SIZE];
    int top = -1;

    // Push items onto the stack
    for (int i = 0; i < SIZE; i++) {
        top++;
        stack[top] = i+1;
    }

    // Get top element of stack
    int top_element = stack_top(stack, top);

    // Print top element of stack
    if (top_element != INT_MIN) {
        cout << "Top element of stack: " << top_element << "\n";
    }
    else {
        cout << "Stack is empty\n";
    }

    return 0;
}
