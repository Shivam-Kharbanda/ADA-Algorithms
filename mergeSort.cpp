#include <iostream>
using namespace std;

void merge(int arr[], int start, int end, int mid) {
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int* left = new int[leftSize];
    int* right = new int[rightSize];

    for (int i = 0; i < leftSize; i++)
        left[i] = arr[start + i];

    for (int i = 0; i < rightSize; i++)
        right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = start;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < leftSize) arr[k++] = left[i++];
    while (j < rightSize) arr[k++] = right[j++];

    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int start, int end) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, end, mid);
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
