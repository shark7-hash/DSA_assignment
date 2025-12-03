#include <iostream>
#include<vector>
#include<stack>
using namespace std;

class MinStack {
    stack<long long> st;
    long long mini; // store current minimum
public:
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        } else {
            if (val < mini) {
                // encode smaller value
                st.push(2LL * val - mini);
                mini = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        long long topVal = st.top();
        st.pop();
        if (topVal < mini) {
            // decode previous minimum
            mini = 2LL * mini - topVal;
        }
    }

    int top() {
        long long topVal = st.top();
        if (topVal < mini) return mini; // encoded value
        return topVal;
    }

    int getMin() {
        return mini;
    }

    bool empty() {
        return st.empty();
    }
};

int main() {
    MinStack s;
    s.push(5);
    s.push(2);
    s.push(10);
    s.push(1);
    cout << "Current Min: " << s.getMin() << "\n"; // 1
    s.pop();
    cout << "Top: " << s.top() << " Min: " << s.getMin() << "\n"; // 10, 2
}
