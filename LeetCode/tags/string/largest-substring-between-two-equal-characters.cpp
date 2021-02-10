#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size(), ans=INT_MIN;
        unordered_map<char, int> f,l;
        for(int i=0;i<n;i++)
            l[s[i]]=i;
        for(int i=n-1;i>=0;i--)
            f[s[i]]=i;
        for(char c: s)
            ans = max(ans, l[c]-f[c]-1);
        return ans;
    }
};


