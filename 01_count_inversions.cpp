#include <vector>
using namespace std;

// Merge function to count split inversions
long long merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;
    long long cnt = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            // arr[left] > arr[right] -> all remaining elements in left half form inversions
            cnt += (mid - left + 1);
            temp.push_back(arr[right++]);
        }
    }
    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++) arr[i] = temp[i - low];
    return cnt;
}

long long mergeSort(vector<int>& arr, int low, int high) {
    long long cnt = 0;
    if (low >= high) return cnt;
    int mid = low + (high - low) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}

// Main Function: Count Inversions
long long numberOfInversions(vector<int>& arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}
