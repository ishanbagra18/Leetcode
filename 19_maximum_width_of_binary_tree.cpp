#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ============================================================================
// Maximum Width of Binary Tree (LeetCode 662)
// ============================================================================
// Approach:
// - Use Level Order Traversal (BFS) assigning each node a 0-indexed position
//   as if the tree were a complete binary tree:
//     - Root index: 0
//     - Left child index:  2 * i + 1
//     - Right child index: 2 * i + 2
// - Width of a level = (last node index - first node index + 1).
// - Overflow Prevention: In deep/skewed trees, 2^depth can exceed integer ranges.
//   We normalize indices at each level by subtracting the minimum index of that
//   level (`levelMin = q.front().second`) before calculating children indices.
//
// Complexity:
// - Time: O(N) where N is the total number of nodes.
// - Space: O(N) for the BFS queue storing at most the maximum level width.
int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;

    int maxWidth = 0;
    // Queue stores pairs: {node, index}
    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});

    while (!q.empty()) {
        int size = q.size();
        unsigned long long levelMin = q.front().second; // Base offset for this level
        unsigned long long firstIdx = 0, lastIdx = 0;

        for (int i = 0; i < size; ++i) {
            TreeNode* curr = q.front().first;
            unsigned long long currIdx = q.front().second - levelMin; // Normalized index
            q.pop();

            if (i == 0) firstIdx = currIdx;
            if (i == size - 1) lastIdx = currIdx;

            if (curr->left) {
                q.push({curr->left, 2 * currIdx + 1});
            }
            if (curr->right) {
                q.push({curr->right, 2 * currIdx + 2});
            }
        }

        maxWidth = max(maxWidth, static_cast<int>(lastIdx - firstIdx + 1));
    }

    return maxWidth;
}
