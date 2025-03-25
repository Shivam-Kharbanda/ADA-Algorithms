#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int partition(vector<int> &arr, int left, int right) {
    int pivot = arr[left], low = left + 1, high = right;

    while (low <= high) {
        while (low <= high && arr[low] <= pivot) low++;
        while (low <= high && arr[high] > pivot) high--;
        if (low < high) swap(arr[low], arr[high]);
    }
    swap(arr[left], arr[high]);
    return high;
}

void quickSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

int main() {
    int n = 1000;

    while (n <= 10000) {
        long long total_time = 0;

        for (int i = 0; i < 10; i++) {
            vector<int> arr(n);
            for (int j = 0; j < n; j++) arr[j] = rand();

            auto start_time = high_resolution_clock::now();
            quickSort(arr, 0, n - 1);
            auto end_time = high_resolution_clock::now();

            total_time += duration_cast<microseconds>(end_time - start_time).count();
        }

        double avg_time = total_time / 10000.0;
        cout << "Size of array: " << n << " | Avg Time (ms): " << avg_time << endl;
        n += 1000;
    }

    return 0;
}
