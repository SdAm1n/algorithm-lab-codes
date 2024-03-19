#include <iostream>
using namespace std;

void selectionSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[m]) m = j;
        }
        if (m != i) swap(arr[i], arr[m]);
    }
}

int main() {
        cout << "Enter Size: ";
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSort(arr, n);
    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}