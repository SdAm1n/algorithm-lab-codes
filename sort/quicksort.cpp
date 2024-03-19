// taking first element as pivot

#include <iostream>
using namespace std;

int partition(int *arr, int l, int h) {
    int pivot = arr[l];
    int i = l, j = h;

    while (i < j) {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;

        // i and j didn't cross. so swap i and j
        if (i < j) swap(arr[i], arr[j]);
    }
    // i and j have crossed. so swap the pivot and j
    swap(arr[l], arr[j]);

    return j;
}

void quickSort(int *arr, int l, int h) {
    if (l < h) {
        int pivot = partition(arr, l, h);

        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot + 1, h);
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);

    cout << "Sorted Array: ";
    printArray(arr, n);

}