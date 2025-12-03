#include <iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temp) {
    int n = temp.size();
    vector<int> ans(n, 0);
    stack<int> st; // store indices of days

    for (int i = 0; i < n; i++) {
        while (!st.empty() && temp[i] > temp[st.top()]) {
            int idx = st.top();
            st.pop();
            ans[idx] = i - idx;
        }
        st.push(i);
    }
    return ans;
}

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = dailyTemperatures(temperatures);

    cout << "Days until warmer: ";
    for (int x : res) cout << x << " ";
}
