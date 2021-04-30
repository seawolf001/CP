#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

//https://leetcode.com/problems/longest-valid-parentheses/discuss/14126/My-O(n)-solution-using-a-stack/243370

// O(1) without dp

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), ans=0;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++) {
            if(s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if(st.empty())
                    st.push(i);
                else
                    ans = max(ans, i-st.top());
            }
            // cout << "i=" << i << " ans=" << ans << endl;
        }
        return ans;
    }
};


