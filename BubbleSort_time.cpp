#include <iostream>
#include <chrono>
#include <vector>
#include <random>

using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 10000);

    for (int n = 1000; n <= 10000; n += 1000) {
        long long total_time = 0;

        for (int i = 0; i < 10; i++) {
            vector<int> arr(n);
            for (int &val : arr) val = dist(gen);

            auto start_time = steady_clock::now();
            bubbleSort(arr);
            auto end_time = steady_clock::now();

            total_time += duration_cast<microseconds>(end_time - start_time).count();
        }

        double avg_time = total_time / 10000.0; // Convert to ms
        cout << "Size of array: " << n << " | Avg Time (ms): " << avg_time << endl;
    }

    return 0;
}
