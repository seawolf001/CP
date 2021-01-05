// Not working

/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;


class Solution {
private:
    unordered_map<int, int> vis;
    unordered_map<int, list<int>> adj;
    bool detect_cycle_topological(int i) {
        if(vis[i]==1) return true; // cycle
        if(vis[i]==2) return false; // completed already
        vis[i]=1;
        for(int x: adj[i]) {
            if(detect_cycle_topological(x))
                return true;
        }
        vis[i]=2; // mark completed
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto e:prerequisites) {
            adj[e[1]].push_front(e[0]);
        }
        for(int i=0;i<numCourses;i++) {
            if(!vis[i]) {
                bool cycle=detect_cycle_topological(i);
                if(cycle) return false;
            }
        }
        return true;
    }
};


