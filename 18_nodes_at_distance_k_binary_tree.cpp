#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
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
// All Nodes Distance K in Binary Tree (LeetCode 863)
// ============================================================================
// Approach:
// 1. Traverse tree (BFS) to map every node to its parent pointer, effectively
//    treating the binary tree as an undirected graph.
// 2. Perform a second BFS radially starting from the target node in 3 directions:
//    - left child
//    - right child
//    - parent
// 3. Maintain a visited set to avoid cycles. Stop when current radial distance = k.
//
// Complexity:
// - Time: O(N) where N is the number of nodes in the binary tree.
// - Space: O(N) for parent map, visited set, and BFS queue.

// Helper function to map each node to its parent
void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr->left) {
            parentMap[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right) {
            parentMap[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

// Main Function: Find all nodes at distance K from target
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    if (!root || !target) return {};

    // Map parent pointers
    unordered_map<TreeNode*, TreeNode*> parentMap;
    markParents(root, parentMap);

    // BFS from target node
    unordered_set<TreeNode*> visited;
    queue<TreeNode*> q;

    q.push(target);
    visited.insert(target);
    int currentDistance = 0;

    while (!q.empty()) {
        int size = q.size();
        if (currentDistance == k) break;

        for (int i = 0; i < size; ++i) {
            TreeNode* curr = q.front();
            q.pop();

            // 1. Move left
            if (curr->left && !visited.count(curr->left)) {
                visited.insert(curr->left);
                q.push(curr->left);
            }

            // 2. Move right
            if (curr->right && !visited.count(curr->right)) {
                visited.insert(curr->right);
                q.push(curr->right);
            }

            // 3. Move up to parent
            if (parentMap.count(curr) && !visited.count(parentMap[curr])) {
                visited.insert(parentMap[curr]);
                q.push(parentMap[curr]);
            }
        }
        currentDistance++;
    }

    // Collect all nodes at distance k
    vector<int> result;
    while (!q.empty()) {
        result.push_back(q.front()->val);
        q.pop();
    }

    return result;
}
