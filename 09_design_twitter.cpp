#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

// Main Class: Design Twitter (LeetCode 355)
class Twitter {
    int timestamp;
    unordered_map<int, unordered_set<int>> followees;
    unordered_map<int, vector<pair<int, int>>> userTweets; // userId -> list of {time, tweetId}

public:
    Twitter() : timestamp(0) {}

    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // Max-heap storing {time, tweetId}
        priority_queue<pair<int, int>> pq;

        // User's own tweets
        for (auto& t : userTweets[userId]) pq.push(t);

        // Tweets from followed users
        for (int followeeId : followees[userId]) {
            for (auto& t : userTweets[followeeId]) {
                pq.push(t);
            }
        }

        vector<int> feed;
        int count = 0;
        while (!pq.empty() && count < 10) {
            feed.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followees[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};
