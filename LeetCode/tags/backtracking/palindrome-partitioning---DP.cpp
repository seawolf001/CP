#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

// [WIP]

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        int n = s.size();
        if(n==0)
            return ans;

        bool ** tracker = new bool * [n];
        for(int i=0;i<n;i++) {
            tracker[i] = new bool[n];
            for(int j=0;j<n;j++)
                tracker[i][j] = false;
        }

        for(int i=0;i<n;i++)
            tracker[i][i] = true; // LEN = 1
        for(int i=0;i<n-1;i++)
            tracker[i][i+1] = s[i]==s[i+1] ? true: false; // LEN = 2
        for(int l=3;l<n;l++) { // LEN >= 3
            for(int st=0;st <= n-l;st++) {
                int end = st+l-1;
                tracker[st][end] = s[st]==s[end] && tracker[st+1][end-1] ? true: false;
            }
        }
        dfs(s, 0, n, curr, ans, tracker);
        for(int i=0;i<n;i++)
            delete[] tracker[i];
        delete[] tracker;
        return ans;
    }
    void dfs(string &s, int idx, int size, vector<string> &curr,
                    vector<vector<string>> &ans, bool ** tracker) {
        if(idx == size) {
            ans.push_back(curr);
            return;
        }
        for(int i=idx; i<size; ++i) {
            if(tracker[idx][i]) {
                curr.push_back(s.substr(idx, i-idx+1));
                dfs(s, i+1, size, curr, ans, tracker);
                curr.pop_back();
            }
        }
    }
};

