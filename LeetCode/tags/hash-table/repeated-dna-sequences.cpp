#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        int n = s.size(), count=0;
        if(n<=10) return {};
        for(int i=0;i<=n-10;i++) mp[s.substr(i,10)]++;
        vector<string> ans;
        for(auto &x:mp) {
            if(x.second>1) ans.push_back(x.first);
        }
        return ans;
    }
};


