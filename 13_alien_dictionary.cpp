#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Main Function: Alien Dictionary (LeetCode 269 / GFG - Topological Sort via Kahn's Algorithm)
// Given a sorted dictionary of alien language words, determine the unique character ordering.
// Complexity: O(C + V + E) time, O(V + E) space (V <= 26)
string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> indegree;

    // Initialize indegree for all unique characters present in the dictionary
    for (const string& word : words) {
        for (char c : word) {
            indegree[c] = 0;
        }
    }

    // Build directed graph from consecutive words
    for (int i = 0; i < (int)words.size() - 1; ++i) {
        const string& w1 = words[i];
        const string& w2 = words[i + 1];
        int len = min((int)w1.size(), (int)w2.size());
        bool diffFound = false;

        for (int j = 0; j < len; ++j) {
            if (w1[j] != w2[j]) {
                // Directed edge: w1[j] -> w2[j] (w1[j] comes before w2[j])
                if (!adj[w1[j]].count(w2[j])) {
                    adj[w1[j]].insert(w2[j]);
                    indegree[w2[j]]++;
                }
                diffFound = true;
                break;
            }
        }

        // Invalid prefix condition: e.g., ["abc", "ab"] is invalid because prefix is placed after
        if (!diffFound && w1.size() > w2.size()) {
            return "";
        }
    }

    // Kahn's Algorithm: Queue nodes with 0 in-degree
    queue<char> q;
    for (const auto& entry : indegree) {
        if (entry.second == 0) {
            q.push(entry.first);
        }
    }

    string order = "";
    while (!q.empty()) {
        char u = q.front();
        q.pop();
        order += u;

        for (char v : adj[u]) {
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // If topological sort does not contain all unique characters, a cycle exists
    return (order.size() == indegree.size()) ? order : "";
}

// GFG wrapper: findOrder(dict, N, K)
string findOrder(string dict[], int N, int K) {
    vector<string> words(dict, dict + N);
    return alienOrder(words);
}
