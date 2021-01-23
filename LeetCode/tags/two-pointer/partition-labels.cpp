#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        for(int i=0;i<s.size(); i++) mp[s[i]]=i;
        vector<int> ans;
        for(int i=0;i<s.size();) {
            int last = mp[s[i]], prev=i;
            // choose i->last but if in b/w others chars then take till mp[c]
            while(i<=last) last = max(last, mp[s[i]]), ++i;
            ans.push_back(i-prev);
        }
        return ans;
    }
};


