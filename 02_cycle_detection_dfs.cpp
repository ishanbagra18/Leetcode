#include <vector>
using namespace std;

// Helper DFS function for undirected graph
bool dfs(int node, int parent, vector<int>& vis, vector<int> adj[]) {
    vis[node] = 1;
    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            if (dfs(neighbor, node, vis, adj)) return true;
        } else if (neighbor != parent) {
            return true; // Visited neighbor not equal to parent indicates a cycle
        }
    }
    return false;
}

// Main Function: Cycle Detection using DFS in Undirected Graph
bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, vis, adj)) return true;
        }
    }
    return false;
}
