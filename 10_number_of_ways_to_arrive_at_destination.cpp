#include <vector>
#include <queue>
using namespace std;

// Main Function: Number of Ways to Arrive at Destination (LeetCode 1976 - Dijkstra + DP)
int countPaths(int n, vector<vector<int>>& roads) {
    long long MOD = 1e9 + 7;
    vector<vector<pair<int, int>>> adj(n);
    for (auto& r : roads) {
        adj[r[0]].push_back({r[1], r[2]});
        adj[r[1]].push_back({r[0], r[2]});
    }

    // Min-heap: {distance, node}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    vector<long long> dist(n, 1e18);
    vector<long long> ways(n, 0);

    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& [v, time] : adj[u]) {
            if (d + time < dist[v]) {
                dist[v] = d + time;
                ways[v] = ways[u];
                pq.push({dist[v], v});
            } else if (d + time == dist[v]) {
                ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
    }
    return ways[n - 1] % MOD;
}
