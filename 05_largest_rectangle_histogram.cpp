#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Main Function: Largest Rectangle in Histogram (Single-pass Monotonic Stack: O(N) time, O(N) space)
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        int currentHeight = (i == n) ? 0 : heights[i];
        while (!st.empty() && heights[st.top()] >= currentHeight) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : (i - st.top() - 1);
            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }
    return maxArea;
}
