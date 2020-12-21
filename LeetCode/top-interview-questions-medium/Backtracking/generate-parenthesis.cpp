// NOT WORKING


/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
private:
    void _generate(vector<string> &ans, int N, string &s, int idx, int open, int close) {
        if(open==N && close==N) {
            ans.push_back(s);
            return;
        }
        if(open <= close) {
            s[idx] = '(';
            _generate(ans, N, s, idx+1, open+1, close);
        } else {
            s[idx] = ')';
            _generate(ans, N, s, idx+1, open, close+1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s(2*n, '$');
        int open=0, close=1, idx=0;
        _generate(ans, ans.size(), s, idx, open, close);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

