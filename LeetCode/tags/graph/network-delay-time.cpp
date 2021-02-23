#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

// Dijkstra’s shortest path algorithm
class Solution {
private:
    typedef pair<int, int> PII;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, list<PII>> adj;
        for (auto &e: times) {
            adj[e[0]].push_front(make_pair(e[2], e[1])); // (s, (w, e))
        }
        vector<int> dist(n+1, INT_MAX);
        dist[0] = dist[k] = 0;
        priority_queue<PII, vector<PII>, greater<PII>> q; // sort on dist.
        q.push(make_pair(0, k));
        int u,v,w;
        while(!q.empty()) {
            PII f = q.top(); q.pop();
            u = f.second; // next chosen node based on dist.
            for(auto &e: adj[u]) {
                v = e.second;
                w = e.first;
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.push(make_pair(dist[v], v));
                }
            }
        }
        int res = *max_element(dist.begin(), dist.end());
        return res == INT_MAX ? -1 : res;
    }
};


