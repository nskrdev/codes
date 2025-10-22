#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        if (key < arr[mid])
            return binarySearch(arr, left, mid - 1, key);
        return binarySearch(arr, mid + 1, right, key);
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    int result = binarySearch(arr, 0, n - 1, key);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}