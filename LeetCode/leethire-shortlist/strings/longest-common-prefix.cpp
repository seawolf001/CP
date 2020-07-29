
/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        string smallest = "", prefix="";
        int minsize = INT_MAX, len=0;
        for(string s: strs) {
            len = s.size();
            if(len < minsize) {
                smallest = s;
                minsize = len;
            }
        }
        for (int i=0; i<minsize; i++){
            char c = smallest[i];
            for(string curr: strs) {
                if(curr[i] != c)
                    return prefix;
            }
            prefix += c;
        }
        return prefix;
    }
};

