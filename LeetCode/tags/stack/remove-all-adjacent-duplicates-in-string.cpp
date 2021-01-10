/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int i=0, n=s.size();
        string ans;
        while(i<n) {
            if(!st.empty() && st.top()==s[i]) {
                st.pop();
                i++;
            } else {
                st.push(s[i++]);
            }
        }
        while(!st.empty()) { ans = st.top()+ans; st.pop(); }
        return ans;
    }
};

