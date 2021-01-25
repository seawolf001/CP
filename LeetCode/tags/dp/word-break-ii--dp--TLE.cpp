#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    vector<string> solver(string &s, int last, vector<string>& words) {
        unordered_map<int, vector<string>> dp;
        unordered_set<string> words_set(words.begin(), words.end());
        dp[-1]={""};
        int n = s.size();
        for(int last=0;last<n;last++) {
            for(int j=0;j<=last;j++) {
                if(j!=0 && dp[j-1].size()==0) continue;
                string sub = s.substr(j, last-j+1);
                bool valid = words_set.find(sub) != words_set.end();
                if(!valid) continue;
                for(string &sentence: dp[j-1]) {
                    dp[last].push_back((sentence == "") ? sub : sentence + " " + sub);
                }
            }
        }
        return dp[n-1];
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return solver(s, s.size()-1, wordDict);
    }
};


