
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    string sortString(string s) {
        int f[26]={0}, n=s.size();
        for(char c:s) f[c-'a']++;
        string ans="";
        while(n--) {
            for(int i=0;i<26;i++){
                if(f[i]) {
                    ans += i+'a';
                    f[i]--;
                }
            }
            for(int i=25;i>=0;i--) {
                if(f[i]){
                    ans += i+'a';
                    f[i]--;
                }
            }
        }
        return ans;
    }
};


