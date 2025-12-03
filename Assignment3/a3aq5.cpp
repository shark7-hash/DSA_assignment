#include <iostream>
#include<stack>
#include<vector>
using namespace std;

bool canBeSortedUsingStack(vector<int>& A) {
    int n = A.size();
    stack<int> st;
    vector<int> B;  
    int need = 1;  

    for (int i = 0; i < n; i++) {
        st.push(A[i]);

        while (!st.empty() && st.top() == need) {
            B.push_back(st.top());
            st.pop();
            need++;
        }
    }
    while (!st.empty() && st.top() == need) {
        B.push_back(st.top());
        st.pop();
        need++;
    }

    return (B.size() == n); // true if fully sorted
}

int main() {
    vector<int> A = {4, 1, 2, 3};
    if (canBeSortedUsingStack(A))
        cout << "Possible to sort using stack\n";
    else
        cout << "Not possible to sort using stack\n";
}
