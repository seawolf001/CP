
/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, -1);
        for (int i=0; i < s.size(); i++) {
            int j = s[i] - 'a';
            if(freq[j] == -1)
                freq[j] = i;
            else
                freq[j] = -2;
        }
        for (auto c: s) {
            int j = freq[c-'a'];
            // cout << c << " "<< j << endl;
            if (j != -1 && j != -2) return j;
        }
        return -1;
    }
};

