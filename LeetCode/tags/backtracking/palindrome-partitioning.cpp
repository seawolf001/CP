#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

// https://leetcode.com/problems/palindrome-partitioning/discuss/41964/Clean-C%2B%2B-backtracking-solution

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        int n = s.size();
        if(n==0)
            return ans;
        dfs(s, 0, n, curr, ans);
        return ans;
    }
    void dfs(string &s, int idx, int size, vector<string> &curr, vector<vector<string>> &ans) {
        if(idx == size) {
            ans.push_back(curr);
            return;
        }
        for(int i=idx; i<size; ++i) {
            if(pelindrome(s, idx, i)) {
                curr.push_back(s.substr(idx, i-idx+1));
                dfs(s, i+1, size, curr, ans);
                curr.pop_back();
            }
        }
    }
    bool pelindrome(string &str, int s, int e) {
        while(s<=e) {
            if(str[s++] != str[e--])
                return false;
        }
        return true;
    }
};


