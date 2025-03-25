// To find max and min element from an array using divivde and conquer method

#include <iostream>
using namespace std;

pair<int, int> findMaxMin(int arr[], int s, int e) {
    if (s == e) 
        return make_pair(arr[s], arr[s]);

    int mid = s + (e - s) / 2;

    pair<int, int> leftResult = findMaxMin(arr, s, mid);
    pair<int, int> rightResult = findMaxMin(arr, mid + 1, e);

    int maxi = max(leftResult.first, rightResult.first);
    int mini = min(leftResult.second, rightResult.second);

    return make_pair(maxi, mini);
}

int main() {
    int arr[] = {12, 7, 19, 5, 39, 2, 8, 11, 22, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    pair<int, int> result = findMaxMin(arr, 0, n - 1);
    
    cout << "Maximum element: " << result.first << endl;
    cout << "Minimum element: " << result.second << endl;

    return 0;
}

