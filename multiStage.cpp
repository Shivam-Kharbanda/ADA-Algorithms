#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

#define INF INT_MAX

int shortestPath(vector<vector<int> > &graph, int n) {
    vector<int> cost(n, INF);
    cost[n - 1] = 0;
    
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] != 0 && cost[j] != INF)
                cost[i] = min(cost[i], graph[i][j] + cost[j]);
        }
    }
    
    return cost[0];
}

int main() {
    int n = 8;
    vector<vector<int> > graph = {
        {0, 2, 3, 0, 0, 0, 0, 0},
        {0, 0, 0, 3, 6, 0, 0, 0},
        {0, 0, 0, 0, 2, 3, 0, 0},
        {0, 0, 0, 0, 0, 0, 4, 0},
        {0, 0, 0, 0, 0, 0, 1, 2},
        {0, 0, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
    
    cout << "Shortest path cost: " << shortestPath(graph, n) << endl;
    return 0;
}


















// #include <iostream>
// #include <vector>
// #include <limits.h>
// using namespace std ;

// #define INF INT_MAX

// int multistageGraph(vector<vector<pair<int,int> > > &graph, int stages, int n)
// // graph - adjacency list where each node stores (neighbor, weight) pairs
// // n - number of vertices (start from 0 index)
// {
//     vector<int> cost(n, INF) ; // stores the minimum cost from vertex i to reach the last node
//     vector<int> path(n, -1) ; // helps reconstruct the shortest path

//     cost[n-1] = 0 ;

//     for(int i=n-2; i>=0; i--)
//     {
//         for(auto edge: graph[i])
//         {
//             int v = edge.first ; // destination edge
//             int w = edge.second ; // weight of edge

//             if(w + cost[v] < cost[i] && cost[v] != INF)
//             {
//                 cost[i] = w + cost[v] ;
//                 path[i] = v ;
//             }
//         }
//     }

//     // Print the minimum cost from source to destination
//     cout << "Minimum cost: " << cost[0] << endl ;

//     // Print the shortest path using backtracking
//     cout << "Path: ";
//     int curr = 0;
//     while (curr != -1) {
//         cout << curr << " ";
//         curr = path[curr];
//     }
//     cout << endl;
// }

// int main() {
//     int n = 8;  
//     int stages = 4;  

//     vector<vector<pair<int, int>>> graph(n);

//     graph[0] = {{1, 1}, {2, 2}, {3, 5}};
//     graph[1] = {{4, 4}, {5, 11}};
//     graph[2] = {{4, 9}, {5, 5}, {6, 16}};
//     graph[3] = {{6, 2}};
//     graph[4] = {{7, 18}};
//     graph[5] = {{7, 13}};
//     graph[6] = {{7, 2}};

//     multistageGraph(graph, stages, n);

//     return 0;
// }