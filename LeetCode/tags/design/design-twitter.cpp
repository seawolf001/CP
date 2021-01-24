#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Twitter {
private:
    set<pair<int, pair<int, int>>> tweets; // <tweetId, userId>
    int globalId;
    unordered_map<int, unordered_set<int>> following; // <userId, unordered_set<followedUserId>>

public:
    /** Initialize your data structure here. */
    Twitter() {
        following.clear();
        tweets.clear();
        globalId=0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets.insert(make_pair(++globalId, make_pair(tweetId, userId)));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted
     * by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        int count = min(10, (int)tweets.size());
        vector<int> ans;
        for(auto x=tweets.rbegin(); count > 0 && x!=tweets.rend(); ++x) {
            auto tweet = (*x).second;
            if(tweet.second==userId || following[userId].find(tweet.second)!=following[userId].end()) {
                ans.push_back(tweet.first);
                --count;
            }
        }
        return ans;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */


