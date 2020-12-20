/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
private:
    int f(string s) {
        int x[26];
        memset(x, 0, sizeof(x));
        for(char c: s) {
            x[c-'a']++;
        }
        for(int i=0;i<26;i++) {
            if (x[i]>0) {
                return x[i];
            }
        }
        return 1;
    }

public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> wf;
        vector<int> qf;
        for(string s: queries)
            qf.push_back(f(s));
        for(string s: words)
            wf.push_back(f(s));
        sort(wf.begin(), wf.end());
        vector<int> ans;
        vector<int>::iterator we = wf.end();
        for(int x: qf) {
            ans.push_back(we - upper_bound(wf.begin(), wf.end(), x));
        }
        return ans;
    }
};


