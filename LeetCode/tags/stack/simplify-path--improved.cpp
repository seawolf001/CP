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
        stack<string> st;
        stringstream ss(path);
        string token="";
        while(getline(ss, token, '/')) {
            if(token=="" || token==".") continue;
            else if(token=="..") {
                if(!st.empty())  st.pop();
            } else {
                st.push(token);
            }
        }
        string ans="";
        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans=="" ? "/" : ans;
    }
};

