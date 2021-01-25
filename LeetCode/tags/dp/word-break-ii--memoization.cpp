#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    unordered_map<int, vector<string>> memoize;
    vector<string> solver(string &s, int last, vector<string>& words) {
        if(last < 0)
            return {""}; // empty sentence
        else if(memoize.find(last) != memoize.end())
            return memoize[last];
        vector<string> ans;
        for(int i=last;i>=0;i--) {
            string sub = s.substr(i, last-i+1);
            bool valid = find(words.begin(), words.end(), sub) != words.end();
            if(!valid) continue; // else append this word in those sentences.
            memoize[i-1] = solver(s, i-1, words);
            for(string sentence: memoize[i-1]) {
                // cout << sentence << " ";
                ans.push_back((sentence == "") ? sub : sentence + " " + sub);
            }
        }
        memoize[last] = ans;
        return memoize[last];
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        memoize.clear();
        return solver(s, s.size()-1, wordDict);
    }
};
