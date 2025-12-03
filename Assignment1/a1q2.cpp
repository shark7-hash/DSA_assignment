#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < k; j++) {
            if (arr[i] == arr[j]) {
                found = true;
                break;
            }
        }
        if (!found)
            arr[k++] = arr[i];
    }

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}

