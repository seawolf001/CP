#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> mp; vector<vector<string>> ans;
        for(string& s: strs) {
            map<char, int> f;
            for(char c: s) f[c]++;
            mp[f].push_back(s);
        }
        for(auto& x:mp) ans.push_back(x.second);
        return ans;
    }
};


