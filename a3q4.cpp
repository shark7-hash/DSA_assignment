#include <iostream>
#include <stack>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

string infixToPostfix(string expr) {
    stack<char> s;
    string result;

    for (char ch : expr) {
        if (isalnum(ch)) result += ch;
        else if (ch == '(') s.push(ch);
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                result += s.top(); s.pop();
            }
            if (!s.empty()) s.pop();
        } else {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                result += s.top(); s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty()) {
        result += s.top(); s.pop();
    }
    return result;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix: " << infixToPostfix(infix) << "\n";
    return 0;
}

