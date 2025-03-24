#include <iostream>
using namespace std;

bool binarySearch(int arr[], int key, int s, int e) {
    if (s > e) 
        return false;

    int mid = s + (e - s) / 2;

    if (arr[mid] == key) 
        return true;

    return (key < arr[mid]) 
        ? binarySearch(arr, key, s, mid - 1) 
        : binarySearch(arr, key, mid + 1, e);
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter the element to search: ";
    cin >> key;

    if (binarySearch(arr, key, 0, n - 1)) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
