#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

struct djs {
    int parent=-1, rank=0;
};

class Solution {
private:
    int find(vector<djs> &sets, int v) {
        if(sets[v].parent != v)
            sets[v].parent = find(sets, sets[v].parent); // path compression
        return sets[v].parent;
    }
    void unionn(vector<djs> &sets, int v1, int v2) {
        if(sets[v1].rank < sets[v2].rank)
            sets[v1].parent = v2;
        else if(sets[v1].rank > sets[v2].rank)
            sets[v2].parent = v1;
        else
            sets[v1].parent = v2, ++sets[v2].rank;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(), v1,v2;
        vector<djs> sets(n+1);
        for(int i=0;i<=n;i++)
            sets[i].parent = i, sets[i].rank=0;
        vector<int> res(2,0);
        for(auto &e: edges) {
            v1 = find(sets, e[0]), v2 = find(sets, e[1]);
            if(v1 == v2)
                res[0]=e[0], res[1]=e[1];
            else
                unionn(sets, v1, v2);
        }
        return res;
    }
};


