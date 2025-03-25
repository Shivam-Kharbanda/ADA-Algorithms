#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }

    void unionSet(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            if (rank[rootI] < rank[rootJ])
                parent[rootI] = rootJ;
            else if (rank[rootI] > rank[rootJ])
                parent[rootJ] = rootI;
            else {
                parent[rootJ] = rootI;
                rank[rootI]++;
            }
        }
    }
};

int kruskal(int n, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), compareEdges);
    DisjointSet ds(n);
    int minCost = 0, edgeCount = 0;

    for (const auto &edge : edges) {
        if (ds.find(edge.src) != ds.find(edge.dest)) {
            ds.unionSet(edge.src, edge.dest);
            minCost += edge.weight;
            edgeCount++;
            cout << edge.src << " -- " << edge.dest << " = " << edge.weight << endl;
            if (edgeCount == n - 1) break;
        }
    }

    if (edgeCount != n - 1) {
        cout << "Graph is not connected, so MST is not possible." << endl;
        return -1;
    }

    return minCost;
}

int main() {
    int n = 5;
    vector<Edge> edges = {
        {0, 1, 2}, {0, 2, 1}, {1, 2, 1},
        {2, 3, 2}, {3, 4, 1}, {4, 2, 2}
    };

    cout << "\nMinimum Spanning Tree cost: " << kruskal(n, edges) << endl;
    return 0;
}
