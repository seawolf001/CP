/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;


class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int maxL=0, n=str.length(), s=0;
        unordered_map<char, int> _map;
        for (int i=0;i<n;i++) {
            char c=str[i];
            if (_map.count(c)!=0) {
                s = max(s, _map[c]+1);
            }
            _map[c]=i;
            maxL = max(maxL, i-s+1);
        }
        return maxL;
    }
};
