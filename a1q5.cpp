#include <iostream>
using namespace std;

int main() {
    int r, c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;

    int mat[r][c];
    cout << "Enter elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat[i][j];

    for (int i = 0; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < c; j++)
            sum += mat[i][j];
        cout << "Sum of row " << i + 1 << " = " << sum << "\n";
    }

    for (int j = 0; j < c; j++) {
        int sum = 0;
        for (int i = 0; i < r; i++)
            sum += mat[i][j];
        cout << "Sum of column " << j + 1 << " = " << sum << "\n";
    }

    return 0;
}
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

