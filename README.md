# Striver A2Z DSA Sheet - Solutions & Implementations

A collection of optimal solutions and data structure implementations from Striver's A2Z DSA Sheet in C++.

## Problems & Topics

| # | Topic / Problem | Technique | Time Complexity | Space Complexity |
|---|---|---|---|---|
| 01 | [Count Inversions](./01_count_inversions.cpp) | Modified Merge Sort | $O(N \log N)$ | $O(N)$ |
| 02 | [Cycle Detection in Undirected Graph](./02_cycle_detection_dfs.cpp) | DFS + Parent tracking | $O(V + 2E)$ | $O(V)$ |
| 03 | [Subsets (Power Set)](./03_subsets.cpp) | Backtracking | $O(2^N \times N)$ | $O(N)$ |
| 04 | [Trapping Rain Water](./04_trapping_rain_water.cpp) | Two Pointers | $O(N)$ | $O(1)$ |
| 05 | [Largest Rectangle in Histogram](./05_largest_rectangle_histogram.cpp) | Monotonic Stack | $O(N)$ | $O(N)$ |
| 06 | [Min Heap Implementation](./06_min_heap_implementation.cpp) | Array-based Binary Heap | Push/Pop: $O(\log N)$, Top: $O(1)$ | $O(N)$ |
| 07 | [Search in Rotated Sorted Array II](./07_search_rotated_sorted_array_2.cpp) | Binary Search (Duplicates) | $O(\log N)$ avg, $O(N)$ worst | $O(1)$ |
| 08 | [Book Allocation Problem](./08_book_allocation_problem.cpp) | Binary Search on Answer | $O(N \log(\sum - \max))$ | $O(1)$ |
| 09 | [Design Twitter](./09_design_twitter.cpp) | Hash Map + Max-Heap | Feed: $O(K \log U)$ | $O(U + T)$ |
| 10 | [Number of Ways to Arrive at Destination](./10_number_of_ways_to_arrive_at_destination.cpp) | Dijkstra + DP Path Counting | $O(E \log V)$ | $O(V + E)$ |
| 11 | [Disjoint Set Union (DSU)](./11_disjoint_set.cpp) | Path Compression + Rank/Size | $O(4\alpha) \approx O(1)$ | $O(N)$ |
| 12 | [Merge k Sorted Lists](./12_merge_k_sorted_lists.cpp) | Min-Heap (Priority Queue) | $O(N \log k)$ | $O(k)$ |
