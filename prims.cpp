#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

void printMST(const vector<int> &parent, const vector<vector<int>> &graph) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < graph.size(); i++)
        cout << parent[i] << " - " << i << " \t" << graph[parent[i]][i] << " \n";
}

void primMST(vector<vector<int>> &graph) {
    int V = graph.size();
    vector<int> key(V, INT_MAX);  // Minimum edge weights
    vector<bool> mstSet(V, false); // Included in MST
    vector<int> parent(V, -1); // Store MST structure

    key[0] = 0; // Start from the first vertex

    for (int count = 0; count < V - 1; count++) {
        int u = -1, mini = INT_MAX;

        // Finding the vertex with the smallest key value
        for (int i = 0; i < V; i++) {
            if (!mstSet[i] && key[i] < mini) {
                mini = key[i];
                u = i;
            }
        }

        mstSet[u] = true; // Include vertex in MST

        // Update adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    vector<vector<int>> graph = { 
        { 0, 2, 0, 6, 0 },
        { 2, 0, 3, 8, 5 },
        { 0, 3, 0, 0, 7 },
        { 6, 8, 0, 0, 9 },
        { 0, 5, 7, 9, 0 } 
    };

    primMST(graph);
    return 0;
}
