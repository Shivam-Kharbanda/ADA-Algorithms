#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define V 9  // Number of vertices

// In this it finds the vertex with the smallest distance not yet included in SPT
int minDistance(int dist[], bool S[]) {
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++)
        if (!S[i] && dist[i] < min)
            min = dist[i], min_index = i;
    return min_index;
}

// This prints the shortest distances from the source
void printSolution(int dist[]) {
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t\t " << dist[i] << endl;
}

// Dijkstra’s algorithm for shortest paths
void dijkstra(int graph[V][V], int src) {
    bool S[V] = {false};  // Tracks included vertices
    int dist[V];  // Stores shortest distances

    fill(dist, dist + V, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i < V; i++) {
        int u = minDistance(dist, S); // Pick min distance vertex
        S[u] = true;

        for (int j = 0; j < V; j++)
            if (!S[j] && graph[u][j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j])
                dist[j] = dist[u] + graph[u][j]; // Relaxation step
    }

    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0); // Run algorithm from source 0
    return 0;
}
