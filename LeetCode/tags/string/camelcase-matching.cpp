#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        int ps = pattern.size();
        for(string &q:queries) {
            int x=0, y=0;
            for(char &c:q) {
                if(x < ps && pattern[x]==c)
                    ++x;
                else if(AZ(c))
                    ++y;
            }
            res.push_back(x==ps && y==0);
        }
        return res;
    }
};

