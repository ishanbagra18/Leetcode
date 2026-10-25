#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

// Main Function: Word Ladder (LeetCode 127 - Shortest Transformation Sequence via BFS)
// Returns the length of the shortest transformation sequence from beginWord to endWord.
// Complexity: O(N * L * 26) time, O(N * L) space, where N = wordList.size(), L = word length.
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    // Hash set for O(1) word lookup
    unordered_set<string> wordSet(wordList.begin(), wordList.end());

    // If endWord is not in the dictionary, no transformation is possible
    if (!wordSet.count(endWord)) return 0;

    // Queue stores pairs of {currentWord, stepsTaken}
    queue<pair<string, int>> q;
    q.push(make_pair(beginWord, 1));

    // Erase beginWord from set to prevent revisiting
    wordSet.erase(beginWord);

    while (!q.empty()) {
        pair<string, int> curr = q.front();
        q.pop();

        string word = curr.first;
        int steps = curr.second;

        if (word == endWord) return steps;

        // Try replacing each character with 'a' through 'z'
        for (int i = 0; i < (int)word.size(); ++i) {
            char originalChar = word[i];

            for (char ch = 'a'; ch <= 'z'; ++ch) {
                if (ch == originalChar) continue;
                word[i] = ch;

                if (wordSet.count(word)) {
                    wordSet.erase(word); // Mark visited
                    q.push(make_pair(word, steps + 1));
                }
            }
            // Backtrack to the original character
            word[i] = originalChar;
        }
    }

    return 0; // No valid transformation sequence found
}
