
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> f(26,0);
        unordered_map<char, bool> vis;
        for(char c:s) {
            f[c-'a']++;
            vis[c]=false;
        }
        stack<char> st;
        for(char c:s) {
            f[c-'a']--;
            if(vis[c]) continue;
            while(!st.empty() && st.top()>c && f[st.top()-'a']>0) {
                vis[st.top()]=false;
                st.pop();
            }
            st.push(c);
            vis[c]=true;
        }
        string ans="";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
