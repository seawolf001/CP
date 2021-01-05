/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;


class Solution {
private:
    vector<int> stack;
    unordered_map<int, int> visited;
    unordered_map<int, list<int>> adj;

    bool topological_dfs(int node) {
        if (visited[node] == 1) return true; //cycle
        if (visited[node] == 2) return false; // already completed
        visited[node] = 1;
        bool cycle = false;
        for(int e: adj[node]) {
            cycle = cycle || topological_dfs(e);
        }
        visited[node] = 2; // mark completed
        stack.push_back(node);
        return cycle;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        stack.clear(); adj.clear(); visited.clear();
        for (auto e: prerequisites) {
            adj[e[1]].push_front(e[0]);
        }
        for(int i=0;i<numCourses; i++) {
            if (!visited[i]) {
                bool cycle = topological_dfs(i);
                if (cycle) return {}; // return empty array/vector
            }
        }
        reverse(stack.begin(), stack.end());
        return stack;
    }
};
