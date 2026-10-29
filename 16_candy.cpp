#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// ============================================================================
// Approach 1: Two-Pass Greedy (Left-to-Right & Right-to-Left)
// ============================================================================
// - Pass 1: Ensure each child has more candies than the left neighbor if rating is higher.
// - Pass 2: Ensure each child has more candies than the right neighbor if rating is higher.
// Complexity: O(N) time, O(N) space.
int candyTwoPass(vector<int>& ratings) {
    int n = ratings.size();
    if (n <= 1) return n;

    vector<int> candies(n, 1);

    // Left-to-Right pass
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Right-to-Left pass
    for (int i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    return accumulate(candies.begin(), candies.end(), 0);
}

// ============================================================================
// Approach 2: Single-Pass Slope / Peak-Valley (Optimal O(1) Space)
// ============================================================================
// - Treats ratings sequence as slopes (increasing, flat, decreasing).
// - Up-slope: counts length of strictly increasing sequence, adding candies.
// - Down-slope: counts length of strictly decreasing sequence, adding candies.
// - Adjusts peak candy count if down-slope exceeds up-slope.
// Complexity: O(N) time, O(1) space.
int candySlope(vector<int>& ratings) {
    int n = ratings.size();
    if (n <= 1) return n;

    int candies = 1; // 1st child always gets at least 1 candy
    int i = 1;

    while (i < n) {
        // Flat surface: adjacent ratings are equal
        if (ratings[i] == ratings[i - 1]) {
            candies += 1;
            i++;
            continue;
        }

        // Increasing slope (Up)
        int peak = 1;
        while (i < n && ratings[i] > ratings[i - 1]) {
            peak++;
            candies += peak;
            i++;
        }

        // Decreasing slope (Down)
        int down = 1;
        while (i < n && ratings[i] < ratings[i - 1]) {
            candies += down;
            down++;
            i++;
        }

        // If the down-slope is longer than the up-slope, the peak child
        // needs more candies to satisfy the right neighbor constraints
        if (down > peak) {
            candies += (down - peak);
        }
    }

    return candies;
}

// Main Function: Candy (LeetCode 135)
int candy(vector<int>& ratings) {
    return candySlope(ratings);
}
