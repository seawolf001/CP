/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s) {
            if(c=='(' || c=='[' || c=='{') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                else if(c==')' && st.top()!='(') return false;
                else if(c==']' && st.top()!='[') return false;
                else if(c=='}' && st.top()!='{') return false;
                else st.pop();
            }
        }
        return st.empty();
    }
};
