
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> mp;
        for(string& s: strs) {
            map<char, int> f;
            for(char c: s) {
                f[c]++;
            }
            if(mp.find(f)!=mp.end()) {
                mp[f].push_back(s);
            } else {
                mp[f] = {};
                mp[f].push_back(s);
            }
        }
        vector<vector<string>> ans;
        for(auto it=mp.begin(); it!=mp.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};


