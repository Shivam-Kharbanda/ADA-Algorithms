#include <iostream>
using namespace std;

int partition(int arr[], int start, int end) {
    int pivot = start;
    int left = start, right = end;

    while (left <= right) {
        while (arr[left] <= arr[pivot]) left++;
        while (arr[right] > arr[pivot]) right--;

        if (left < right)
            swap(arr[left], arr[right]);
    }

    swap(arr[pivot], arr[right]);
    return right;
}

void quickSort(int arr[], int start, int end) {
    if (start >= end) return;

    int pivotIndex = partition(arr, start, end);
    quickSort(arr, start, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, end);
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array is: ";
    for (int num : arr)
        cout << num << " ";
    
    cout << endl;
    return 0;
}
