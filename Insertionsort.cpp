#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

void insertionSort(vector<int> &arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n = 1000;
    while (n <= 10000) {
        long long total_time = 0;

        for (int trial = 0; trial < 10; trial++) { 
            vector<int> arr(n);
            for (int &val : arr) {
                val = rand();
            }

            auto start_time = high_resolution_clock::now();
            insertionSort(arr, n);
            auto end_time = high_resolution_clock::now();

            total_time += duration_cast<microseconds>(end_time - start_time).count();
        }

        double avg_time = total_time / 10.0 / 1000.0;
        cout << "Array Size: " << n << " | Avg Time (ms): " << avg_time << endl;

        n += 1000;
    }

    return 0;
}
