#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib> // for rand()

using namespace std;
using namespace std::chrono;

void selectionSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    int n = 1000;
    
    while (n <= 10000) {
        long long totalDuration = 0; // Store time in microseconds
        
        for (int test = 0; test < 10; test++) {
            // Generate a random array of size n
            vector<int> arr(n);
            for (int j = 0; j < n; j++) {
                arr[j] = rand();
            }

            // Measure the start time
            auto startTime = high_resolution_clock::now();

            // Sort the array using Selection Sort
            selectionSort(arr, n);

            // Measure the end time
            auto endTime = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(endTime - startTime).count();
            totalDuration += duration;
        }

        double avgTime = totalDuration / 10.0 / 1000.0; // Convert to milliseconds
        cout << "Array Size: " << n << " | Avg Time (ms): " << avgTime << endl;

        n += 1000;
    }

    return 0;
}
