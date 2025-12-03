#include <iostream>
using namespace std;

#define MAX 100
int stackArr[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stackArr[++top] = val;
    cout << val << " pushed.\n";
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << stackArr[top--] << " popped.\n";
}

bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top == MAX - 1);
}

void peek() {
    if (isEmpty()) cout << "Stack is empty.\n";
    else cout << "Top element = " << stackArr[top] << "\n";
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--)
        cout << stackArr[i] << " ";
    cout << "\n";
}

int main() {
    int choice, val;
    do {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; push(val); break;
            case 2: pop(); break;
            case 3: cout << (isEmpty() ? "Stack is empty\n" : "Stack is not empty\n"); break;
            case 4: cout << (isFull() ? "Stack is full\n" : "Stack is not full\n"); break;
            case 5: display(); break;
            case 6: peek(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 7);
    return 0;
}

