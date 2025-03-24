#include <iostream>
#include <stack>
using namespace std;

int partition(int arr[], int start, int end) {
    int pivot = start, left = start, right = end;

    while (left <= right) {
        while (arr[left] <= arr[pivot]) left++;
        while (arr[right] > arr[pivot]) right--;

        if (left < right)
            swap(arr[left], arr[right]);
    }

    swap(arr[pivot], arr[right]);
    return right;
}

void quickSort(int arr[], int size) {
    stack<int> st;
    st.push(0);
    st.push(size - 1);

    while (!st.empty()) {
        int end = st.top(); st.pop();
        int start = st.top(); st.pop();

        int pivotIndex = partition(arr, start, end);

        if (pivotIndex - 1 > start) {
            st.push(start);
            st.push(pivotIndex - 1);
        }

        if (pivotIndex + 1 < end) {
            st.push(pivotIndex + 1);
            st.push(end);
        }
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, n);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    
    cout << endl;
    return 0;
}
