#include <iostream>
#include<vector>

using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;  // will store indices

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = arr[st.top()];
        }
        st.push(i);
    }
    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> ans = nextGreaterElement(arr);

    cout << "Next Greater Elements: ";
    for (int x : ans) cout << x << " ";
}
