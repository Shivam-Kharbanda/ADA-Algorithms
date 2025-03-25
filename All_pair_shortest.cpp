#include <iostream>
#include <vector>
using namespace std;

void floydWarshall(vector<vector<int>> &graph, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][k] != -1 && graph[k][j] != -1) {
                    if (graph[i][j] == -1 || graph[i][j] > graph[i][k] + graph[k][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    int n = 4;
    vector<vector<int>> graph = {
        {0, 8, -3, -1},
        {7, 0, -1, 3},
        {-1, 4, 0, -1},
        {-1, -1, 2, 0}
    };

    floydWarshall(graph, n);

    for (const auto &row : graph) {
        for (int val : row) {
            cout << (val == -1 ? "INF" : to_string(val)) << "\t";
        }
        cout << endl;
    }

    return 0;
}
