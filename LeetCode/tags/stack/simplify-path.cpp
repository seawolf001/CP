/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        if(n==0) return "";
        stack<string> st;
        int i=0;
        while(i<n) {
            string curr="";
            if(path[i]=='/') {
                i++;
                continue;
            } else if(path[i]=='.'){
                string dots="";
                while(i<n && path[i]=='.') {
                    dots += '.';
                    i++;
                }
                if((i<n && path[i]!='/')||dots.size()>2) {
                    curr=dots;
                } else if(dots.size()==2) {
                    if(!st.empty()) {
                        st.pop();
                    }
                } else if(dots.size()==1) {
                    continue;
                }
            }
            while(i<n && path[i]!='.' && path[i]!='/') {
                curr+=path[i];
                i++;
            }
            if(curr!="") {
                st.push(curr);
            }
        }
        if(st.empty()) return "/";
        string ans="";
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

