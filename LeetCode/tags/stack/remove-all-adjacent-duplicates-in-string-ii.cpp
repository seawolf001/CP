/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<char> st;
        int i=0;
        while(i<n) {
            if(!st.empty() && st.top()==s[i]) {
                char c=st.top();
                int count=0;
                while(!st.empty() && st.top()==c) {++count; st.pop();}
                while(c==s[i]) {i++; ++count;}
                int r = count % k;
                // cout << "char=" << c << " count=" << count <<  " r="<< r <<endl;
                if(r==0) continue;
                while(r--) st.push(c);
            } else {
                st.push(s[i++]);
            }
        }
        string ans="";
        while(!st.empty()) { ans = st.top()+ans; st.pop(); }
        return ans;
    }
};


