#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int f[26]={0}; int ans=0;
        for(char &c:allowed)
            f[c-'a']++;
        for(string &w:words) {
            bool flag=true;
            for(char &c:w) {
                if(f[c-'a']==0) {
                    flag=false;
                    break;
                }
            }
            if(flag) ++ans;
        }
        return ans;
    }
};


