#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int>lp;
        transform(licensePlate.begin(), licensePlate.end(), licensePlate.begin(), ::tolower);
        for(char &c:licensePlate) lp[c]++;
        string ans=""; int len=INT_MAX;
        for(string &word:words) {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            unordered_map<char, int> w;
            for(char &c: word) w[c]++;
            bool flag=true;
            for(int i=0;i<26;i++) {
                char tmp = (char)('a'+i);
                if(lp[tmp]!=0 && lp[tmp]>w[tmp]) {
                    flag=false; break;
                }
            }
            if(flag && len>word.size()) {
                len=word.size(); ans=word;
            }
        }
        return ans;
    }
};


