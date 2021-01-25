#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    unordered_map<int, bool> memoize;
    bool solver(string &s, int last, vector<string>& wordDict) {
        if(last < 0) return true;
        if(memoize.find(last) != memoize.end()) return memoize[last];
        for(int i=0;i<=last;i++) {
            string sub = s.substr(i, last-i+1);
            bool valid = find(wordDict.begin(), wordDict.end(), sub) != wordDict.end();
            memoize[i-1] = solver(s, i-1, wordDict);
            if(valid && memoize[i-1]) return true;
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memoize.clear();
        return solver(s, s.size()-1, wordDict);
    }
};


