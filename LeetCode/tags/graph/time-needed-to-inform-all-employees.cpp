#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    int dfs(int id, int n, vector<int>& manager, vector<int>& informTime, int &res) {
        if(manager[id] != -1) {
            informTime[id] += dfs(manager[id], n, manager, informTime, res);
            manager[id] = -1; // visited
        }
        res = max(res, informTime[id]);
        return informTime[id];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res=INT_MIN;
        for(int i=0;i<n;i++) {
            dfs(i,n,manager,informTime, res);
        }
        return res;
    }
};


