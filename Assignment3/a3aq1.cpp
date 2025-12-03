#include <bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);   // default -1 if no smaller element exists
    stack<int> st;               // will store elements (monotonic stack)

    for (int i = 0; i < n; i++) {
        // Pop all elements >= current one
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // If stack is not empty, top is the nearest smaller
        if (!st.empty()) {
            result[i] = st.top();
        }

        // Push current element for next iterations
        st.push(arr[i]);
    }
    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> ans = nearestSmallerElement(arr);

    cout << "Nearest Smaller Elements: ";
    for (int i = 0; i < ans.size(); i++) 
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
