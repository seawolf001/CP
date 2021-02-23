#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    unordered_map<string, list<pair<string, double>>> adj;
    unordered_set<string> vis;
    bool dfs(string node, string end, double &curr) {
        if(node == end)
            return true;
        vis.insert(node);
        for(auto &e: adj[node]) {
            if(vis.find(e.first) != vis.end())
                continue;
            double prev = curr;
            curr = curr * e.second;
            if((dfs(e.first, end, curr)))
                return true; // no need to explore other paths.
            else
                curr = prev;
        }
        return false;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
        vector<vector<string>>& queries) {
        // form a graph a-->b-->c;
        adj.clear();
        for(int i=0;i < equations.size();i++) {
            adj[equations[i][0]].push_front(make_pair(equations[i][1], values[i]));
            adj[equations[i][1]].push_front(make_pair(equations[i][0], 1/values[i]));
        }
        int n = queries.size();
        vector<double> res(n, 0.00);
        for(int i=0;i<n;i++) {
            vis.clear();
            string s = queries[i][0], e = queries[i][1];
            if(adj.find(s) == adj.end() || adj.find(e) == adj.end())
                res[i] = -1;
            else {
                double curr=1;
                res[i] = dfs(s, e, curr) ? curr : -1;
            }
        }
        return res;
    }
};


