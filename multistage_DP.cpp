#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

void multistageGraph(vector<vector<pair<int, int>>> &graph, int stages, int n) {
    vector<int> cost(n, INF);
    vector<int> path(n, -1);
    cost[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        for (const auto &edge : graph[i]) {
            int nextNode = edge.first;
            int weight = edge.second;

            if (cost[nextNode] != INF && weight + cost[nextNode] < cost[i]) {
                cost[i] = weight + cost[nextNode];
                path[i] = nextNode;
            }
        }
    }

    cout << "Minimum cost from source to destination: " << cost[0] << endl;
    cout << "Path: ";
    int curr = 0;
    while (curr != -1) {
        cout << curr << " ";
        curr = path[curr];
    }
    cout << endl;
}

int main() {
    int n = 8;
    int stages = 4;
    vector<vector<pair<int, int>>> graph(n);

    graph[0] = {{1, 3}, {2, 6}, {3, 7}};
    graph[1] = {{4, 5}, {5, 10}};
    graph[2] = {{4, 8}, {5, 6}, {6, 15}};
    graph[3] = {{6, 3}};
    graph[4] = {{7, 20}};
    graph[5] = {{7, 12}};
    graph[6] = {{7, 4}};

    multistageGraph(graph, stages, n);

    return 0;
}
