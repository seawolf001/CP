#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> ans, sf(26,0), pf(26,0);
        if(m > n)
            return ans;
        for(int i=0;i<m;i++) {
            pf[p[i]-'a']++;
            sf[s[i]-'a']++;
        }
        if(sf == pf)
            ans.push_back(0);
        for(int i=m;i<n;i++) {
            sf[s[i]-'a']++;
            sf[s[i-m]-'a']--;
            if(sf==pf)
                ans.push_back(i-m+1);
        }
        return ans;
    }
};


