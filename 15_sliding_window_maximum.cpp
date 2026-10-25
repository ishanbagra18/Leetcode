#include <vector>
#include <deque>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// ============================================================================
// Pattern 1: Fixed-Size Sliding Window — Sliding Window Maximum (LeetCode 239)
// ============================================================================
// Approach: Monotonic Decreasing Deque storing indices of candidate maximums.
// Complexity: O(N) time (each index pushed & popped at most once), O(k) auxiliary space.
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> dq; // Stores indices of potential maximums in descending value order
    vector<int> result;

    for (int i = 0; i < n; ++i) {
        // 1. Remove indices that fall outside the current window [i - k + 1, i]
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // 2. Maintain monotonic decreasing order:
        // Evict smaller elements from the back as they can never be the maximum again
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        // 3. Add current element's index
        dq.push_back(i);

        // 4. Record maximum once the first full window of size k is formed
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

// ============================================================================
// Pattern 2: Variable-Size Sliding Window — Longest Substring Without Repeating Characters (LeetCode 3)
// ============================================================================
// Approach: Dynamic window [left, right] with last-seen character indices.
// Complexity: O(N) time, O(min(N, alphabet_size)) space.
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeen;
    int maxLen = 0;
    int left = 0;

    for (int right = 0; right < (int)s.size(); ++right) {
        char ch = s[right];
        if (lastSeen.count(ch) && lastSeen[ch] >= left) {
            left = lastSeen[ch] + 1; // Jump left pointer past previously seen index
        }
        lastSeen[ch] = right;
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}
