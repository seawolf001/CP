#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int f[26]={0}, ans=0;
        for(char &c: chars) f[c-'a']++;
        for(string &w:words) {
            int wf[26]={0};
            for(char &c:w)
                wf[c-'a']++;
            bool flag=true;
            for(int i=0;i<26;i++) {
                if(wf[i]>f[i])
                    flag=false;
            }
            if(flag)
                ans += w.size();
        }
        return ans;
    }
};


