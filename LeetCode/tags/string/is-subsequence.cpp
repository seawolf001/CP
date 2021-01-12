
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s==t) return true;
        int i=0, n=s.size();
        for(char c:t) {
            if(c==s[i]) i++;
            if(i==n) return true;
        }
        return false;;
    }
};


