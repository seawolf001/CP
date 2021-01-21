#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    map<vector<int>, vector<int>> mp;
    for(int i=0;i<A.size();i++) {
        string s = A[i]; vector<int>f(256,0);
        for(char c:s) f[c]++;
        mp[f].push_back(i+1);
    }
    vector<vector<int>> ans;
    for(auto &p:mp) {
        sort(p.second.begin(), p.second.end());
        ans.push_back(p.second);
    }
    return ans;
}



