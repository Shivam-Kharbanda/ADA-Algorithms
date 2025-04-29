# Analysis and Design of Algorithms

## 1D Array Peak Element
A peak element is an element that is greater than or equal to its neighbors in a 1D array.

- **Time Complexity:** O(log n) (using binary search)

## Activity Selection Problem
A greedy algorithm to select the maximum number of non-overlapping activities, given their start and end times.

- Used in scheduling and resource allocation.
- **Time Complexity:** O(n log n)

## All-Pairs Shortest Path Algorithm
Finds the shortest paths between every pair of vertices in a weighted graph.

- Used in traffic navigation, network optimization, and logistics.
- **Time Complexity:** O(n³)

## Bubble Sort
Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

- Useful for small datasets where simplicity is preferred over efficiency.
- **Time Complexity:**
  - Best Case: **O(n)** (when already sorted)
  - Average Case: **O(n²)**
  - Worst Case: **O(n²)** (when sorted in reverse order)

## Dijkstra’s Algorithm
A greedy algorithm used to find the shortest path from a single source vertex to all other vertices in a weighted graph (with non-negative weights).

- Applied in network routing, GPS navigation, and AI pathfinding.
- **Time Complexity:** O((V + E) log V)

## Knapsack Problem (Greedy Approach)
Used for the **Fractional Knapsack Problem**, where items can be taken in fractions based on their value-to-weight ratio.

- Applied in finance and storage optimization.
- **Time Complexity:** O(n log n)

## Kruskal’s Algorithm
A greedy algorithm to find the Minimum Spanning Tree (MST) of a graph by selecting edges in increasing order of weight while avoiding cycles.

- Used in network design (roads, electrical grids, etc.).
- **Time Complexity:** O(E log V)

## Magic Square
A magic square is a grid of distinct numbers where the sum of numbers in each row, column, and both diagonals is the same.

- **Time Complexity:** O(n²)

## Matrix Multiplication (Divide and Conquer)
This method recursively breaks down large matrices into smaller submatrices, multiplies them, and combines the results.

- **Time Complexity:** O(n³)

## Matrix Multiplication (Iterative)
Matrix multiplication involves multiplying two matrices A (m × n) and B (n × p) to produce a resultant matrix C (m × p).

- Used in computer graphics, machine learning, and scientific computing.
- **Time Complexity:** O(mnp)

## Merge Sort
Merge Sort is a divide-and-conquer sorting algorithm that splits the array into smaller parts, sorts them, and then merges them back together.

- Preferred for large datasets due to its efficiency and stability.
- **Time Complexity:** O(n log n) for best, average, and worst cases.

## Min and Max Element in an Array (Divide and Conquer)
Finding the minimum and maximum element in an array using the divide-and-conquer approach reduces the number of comparisons.

- **Time Complexity:** ~3n/2 comparisons, which is more efficient than the naive O(n) approach.

## Prim’s Algorithm
Another greedy algorithm for finding the Minimum Spanning Tree (MST), growing the tree from an arbitrary starting vertex.

- Applied in infrastructure design for minimum-cost connections.
- **Time Complexity:** O(E log V)

## Quick Sort
Quick Sort is a divide-and-conquer algorithm that selects a pivot element, partitions the array into two subarrays, and recursively sorts them.

- Commonly used for in-place sorting.
- **Time Complexity:**
  - Best Case: **O(n log n)**
  - Average Case: **O(n log n)**
  - Worst Case: **O(n²)** (if poorly chosen pivot)

## Selection Sort
Selection Sort repeatedly selects the smallest (or largest) element from the unsorted portion of the list and swaps it with the first element of the unsorted section.

- Minimizes swaps compared to Bubble Sort.
- **Time Complexity:** O(n²) for all cases since it scans the array in every pass, even when already sorted.

  ![image](https://github.com/user-attachments/assets/00a4aec2-b854-4a8d-b96e-646de2bb2db2)


## Strassen’s Matrix Multiplication
Strassen’s algorithm reduces the number of multiplications from 8 to 7 when multiplying two matrices.

- **Time Complexity:** O(n^{2.81})

This repository contains implementations of these algorithms in various programming languages, along with explanations and example use cases.



