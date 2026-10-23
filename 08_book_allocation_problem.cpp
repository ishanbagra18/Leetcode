#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// Helper: Check count of students needed with max allowed pages per student
int countStudents(vector<int>& arr, int maxPages) {
    int students = 1, pagesAllocated = 0;
    for (int pages : arr) {
        if (pagesAllocated + pages <= maxPages) {
            pagesAllocated += pages;
        } else {
            students++;
            pagesAllocated = pages;
        }
    }
    return students;
}

// Main Function: Book Allocation Problem (Binary Search on Answer: O(N * log(sum - max)))
int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1; // impossible if students > books

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (countStudents(arr, mid) <= m) {
            high = mid - 1; // try smaller maximum pages
        } else {
            low = mid + 1;
        }
    }
    return low;
}
