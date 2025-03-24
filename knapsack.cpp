#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item {
    int profit, weight;
};


bool compare(const Item &a, const Item &b) {
    return (double)a.profit / a.weight > (double)b.profit / b.weight;
}

double fractionalKnapsack(int capacity, vector<Item> &items) {
    sort(items.begin(), items.end(), compare);
    
    double totalProfit = 0.0;
    int remainingCapacity = capacity;
    
    for (size_t i = 0; i < items.size(); i++) {
        if (remainingCapacity >= items[i].weight) {
            remainingCapacity -= items[i].weight;
            totalProfit += items[i].profit;
        } else {
            totalProfit += items[i].profit * ((double)remainingCapacity / items[i].weight);
            break; 
        }
    }
    
    return totalProfit;
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<Item> items(n);
    cout << "Enter profit and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].profit >> items[i].weight;
    }

    double maxProfit = fractionalKnapsack(capacity, items);
    cout << "Maximum profit: " << fixed << setprecision(2) << maxProfit << endl;
    
    return 0;
}
