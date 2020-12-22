/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
private:
    set<char> digits{'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
public:
    int calculate(string s) {
        long long ans=0, temp=0, t=0;
        int n = s.size(), i=0;
        char op='+';
        stack<long long> st;

        for(int i=0;i<n;i++) {
           if(digits.find(s[i]) != digits.end()) {
                temp = temp * 10 + s[i] - '0';
            }
            if ((s[i]!=' ' && digits.find(s[i]) == digits.end()) || i==n-1) {
                if(op=='+')
                    st.push(temp);
                else if(op=='-')
                    st.push(-temp);
                else {
                    t = st.top();
                    st.pop();
                    if(op=='*') {
                        st.push(t*temp);
                    } else {
                        st.push(t/temp);
                    }
                }
                op = s[i];
                temp = 0;
            }
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};


