
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
                int c=0;
                while(s[i]==')') {
                    ++c; ++i;
                }
                if(!st.empty()) {
                    if(c==1) {
                        ans +=1; // insert another ')' and pop '(' matching to '))'
                        st.pop();
                    } else {
                        while(!st.empty() && c>=2) {
                            st.pop();
                            c-=2;
                        }
                        while(c>=2) {
                            // insert ( for every ))
                            ans += 1;
                            c -= 2;
                        }
                        if(c==1 && st.empty()) ans += 2; // // have ), add () to make it ())
                        else if(c==1) { ans +=1; st.pop(); } // insert another ')' and pop '(' matching to '))'
                    }
                } else {
                    while(c>=2) {
                        // insert ( for every ))
                        ans += 1;
                        c -= 2;
                    }
                    if(c==1) ans += 2; // have ), add () to make it ())
                }
            }
        }
        while(!st.empty()) { ans+=2; st.pop(); }
        return ans;
    }
};


