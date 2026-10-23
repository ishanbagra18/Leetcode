#include <vector>
#include <algorithm>
using namespace std;

// Main Function: Trapping Rain Water (Optimal Two-Pointer approach: O(N) time, O(1) space)
int trap(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n - 1;
    int maxLeft = 0, maxRight = 0;
    int waterTrapped = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= maxLeft) {
                maxLeft = height[left];
            } else {
                waterTrapped += maxLeft - height[left];
            }
            left++;
        } else {
            if (height[right] >= maxRight) {
                maxRight = height[right];
            } else {
                waterTrapped += maxRight - height[right];
            }
            right--;
        }
    }
    return waterTrapped;
}
