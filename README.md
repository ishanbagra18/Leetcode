# 🚀 Striver A2Z DSA Sheet — Tracker & Checklist

A clean, modular repository with optimal C++ solutions and data structure implementations from **Striver's A2Z DSA Sheet**.

---

### 📊 Progress Tracker
- **Total Solved in this Set:** 12 / 12 (100%)
- **Status:** 🟢 Complete


```

Progress: [████████████████████████████████] 100%
```

---

## 📋 Topic-Wise Checklist

### 1. 🧮 Arrays & Two Pointers
- [x] **[01. Count Inversions](./01_count_inversions.cpp)** `Hard`
  - **Approach:** Merge Sort (Count split inversions)
  - **Complexity:** $O(N \log N)$ time, $O(N)$ space
- [x] **[04. Trapping Rain Water](./04_trapping_rain_water.cpp)** `Hard`
  - **Approach:** Two-Pointer Prefix/Suffix maximums
  - **Complexity:** $O(N)$ time, $O(1)$ space

### 2. 🔍 Binary Search
- [x] **[07. Search in Rotated Sorted Array II](./07_search_rotated_sorted_array_2.cpp)** `Medium`
  - **Approach:** Binary Search with duplicate shrinking (`low++`, `high--`)
  - **Complexity:** $O(\log N)$ average, $O(N)$ worst, $O(1)$ space
- [x] **[08. Book Allocation Problem](./08_book_allocation_problem.cpp)** `Hard`
  - **Approach:** Binary Search on Answer space `[max(arr), sum(arr)]`
  - **Complexity:** $O(N \log(\sum - \max))$ time, $O(1)$ space

### 3. 🔁 Recursion & Backtracking
- [x] **[03. Subsets / Power Set](./03_subsets.cpp)** `Medium`
  - **Approach:** Backtracking (Pick / Don't Pick)
  - **Complexity:** $O(2^N \times N)$ time, $O(N)$ space

### 4. 📚 Stack & Queue
- [x] **[05. Largest Rectangle in Histogram](./05_largest_rectangle_histogram.cpp)** `Hard`
  - **Approach:** Single-pass Monotonic Stack
  - **Complexity:** $O(N)$ time, $O(N)$ space

### 5. ⚡ Heap / Priority Queue
- [x] **[06. Min Heap Implementation](./06_min_heap_implementation.cpp)** `Medium`
  - **Approach:** Array-based Binary Heap with `heapifyUp` & `heapifyDown`
  - **Complexity:** Push/Pop $O(\log N)$, Top $O(1)$
- [x] **[09. Design Twitter (LeetCode 355)](./09_design_twitter.cpp)** `Medium`
  - **Approach:** Hash Map + Max-Heap feed aggregation
  - **Complexity:** Feed $O(K \log U)$
- [x] **[12. Merge k Sorted Lists](./12_merge_k_sorted_lists.cpp)** `Hard`
  - **Approach:** Min-Heap storing current list heads
  - **Complexity:** $O(N \log k)$ time, $O(k)$ space

### 6. 🌐 Graphs & Disjoint Set
- [x] **[02. Cycle Detection in Undirected Graph (DFS)](./02_cycle_detection_dfs.cpp)** `Medium`
  - **Approach:** Depth First Search with parent node tracking
  - **Complexity:** $O(V + 2E)$ time, $O(V)$ space
- [x] **[10. Number of Ways to Arrive at Destination](./10_number_of_ways_to_arrive_at_destination.cpp)** `Medium / Hard`
  - **Approach:** Dijkstra algorithm + DP shortest-path counting (modulo $10^9+7$)
  - **Complexity:** $O(E \log V)$ time, $O(V + E)$ space
- [x] **[11. Disjoint Set Union (DSU)](./11_disjoint_set.cpp)** `Concept / Template`
  - **Approach:** Path Compression + Union by Size / Rank
  - **Complexity:** $O(4\alpha) \approx O(1)$ per operation

---

## 📑 Master Solutions Index

| Status | # | Problem / Topic | Category | Difficulty | Optimal Complexity | Solution File |
| :---: | :---: | :--- | :--- | :---: | :--- | :---: |
| [x] | 01 | Count Inversions | Arrays | 🔴 Hard | $O(N \log N)$ / $O(N)$ | [Code](./01_count_inversions.cpp) |
| [x] | 02 | Cycle Detection using DFS | Graphs | 🟡 Medium | $O(V + 2E)$ / $O(V)$ | [Code](./02_cycle_detection_dfs.cpp) |
| [x] | 03 | Subsets (Power Set) | Backtracking | 🟡 Medium | $O(2^N \times N)$ / $O(N)$ | [Code](./03_subsets.cpp) |
| [x] | 04 | Trapping Rain Water | Two Pointers | 🔴 Hard | $O(N)$ / $O(1)$ | [Code](./04_trapping_rain_water.cpp) |
| [x] | 05 | Largest Rectangle in Histogram | Monotonic Stack | 🔴 Hard | $O(N)$ / $O(N)$ | [Code](./05_largest_rectangle_histogram.cpp) |
| [x] | 06 | Min Heap Implementation | Heap | 🟡 Medium | Push/Pop $O(\log N)$, Top $O(1)$ | [Code](./06_min_heap_implementation.cpp) |
| [x] | 07 | Search in Rotated Sorted Array II | Binary Search | 🟡 Medium | $O(\log N)$ / $O(1)$ | [Code](./07_search_rotated_sorted_array_2.cpp) |
| [x] | 08 | Book Allocation Problem | Binary Search | 🔴 Hard | $O(N \log(\sum - \max))$ / $O(1)$ | [Code](./08_book_allocation_problem.cpp) |
| [x] | 09 | Design Twitter | Design / Heap | 🟡 Medium | Feed $O(K \log U)$ | [Code](./09_design_twitter.cpp) |
| [x] | 10 | Number of Ways to Arrive at Destination | Graph / Dijkstra | 🟡 Medium | $O(E \log V)$ / $O(V + E)$ | [Code](./10_number_of_ways_to_arrive_at_destination.cpp) |
| [x] | 11 | Disjoint Set Union (DSU) | Graph / Template | 🟢 Fundamental | $O(4\alpha) \approx O(1)$ | [Code](./11_disjoint_set.cpp) |
| [x] | 12 | Merge k Sorted Lists | Linked List / Heap | 🔴 Hard | $O(N \log k)$ / $O(k)$ | [Code](./12_merge_k_sorted_lists.cpp) |
