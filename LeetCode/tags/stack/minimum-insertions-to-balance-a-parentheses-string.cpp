
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int ans=0; int closed=0;
        for(int i=0;i<s.size();) {
            if(s[i]=='(') {
                st.push(s[i++]);
            } else {
                // if st.empty()!=false ==> insert another ')' and pop '(' matching to '))'
                // else have ), add () to make it ())
                int c=0;
                while(s[i]==')') { ++c; ++i; }
                while(c>=2) {
                    c -= 2;
                    if(!st.empty()) st.pop();
                    else ans += 1;
                }
                if(c==1 && !st.empty()) { ans +=1; st.pop(); }
                else if(c==1 && st.empty()) ans += 2;
            }
        }
        while(!st.empty()) { ans+=2; st.pop(); }
        return ans;
    }
};

