
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        unordered_set<string> hs;
        int n=s.size();
        for(int k=n/2;k>=1;k--) {
            if(n%k!=0) continue;
            string ss = "";
            int L=n/k;
            while(L--) ss += s.substr(0,k);
            if(ss==s) return true;
        }
        return false;
    }
};
