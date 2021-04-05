#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

// https://leetcode.com/problems/verifying-an-alien-dictionary/discuss/203185/JavaC%2B%2BPython-Mapping-to-Normal-Order

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mapping[26]={};
        for(int i=0;i<26;i++)
            mapping[order[i]-'a'] = i;
        for(string &w: words)
            for(char &c: w)
                c = mapping[c-'a'];
        return is_sorted(words.begin(), words.end());
    }
};


