#include <iostream>
using namespace std;
int arr[1005];

void merge(int l, int r, int mid) {
    int l_sz = mid - l + 1;
    int r_sz = r - mid;

    int larr[l_sz + 1];
    int rarr[r_sz + 1];

    for (int i = 0; i < l_sz; i++) {
        larr[i] = arr[i + l];
    }

    for (int i = 0; i < r_sz; i++) {
        rarr[i] = arr[i + mid + 1];
    }

    larr[l_sz] = rarr[r_sz] = INT_MAX;

    int l_i = 0, r_i = 0;

    for (int i = l; i <= r; i++) {
        if (larr[l_i] <= rarr[r_i]) {
            arr[i] = larr[l_i];
            l_i++;
        }
        else {
            arr[i] = rarr[r_i];
            r_i++;
        }
    }
}

void mergeSort(int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, r, mid);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i];

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    cout << endl;
}