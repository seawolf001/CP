/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;


class RecentCounter {
private:
    queue<int> q;
public:
    RecentCounter() {
        q = queue<int>();
    }

    int ping(int t) {
        int x = t - 3000;
        if(q.empty()) {
            q.push(t);
        } else {
            while(!q.empty() && q.front() < x) {
                q.pop();
            }
            q.push(t);
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

