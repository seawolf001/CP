#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<char> st; int n=s.size();
        for(char &c:s) if(isalpha(c)) st.push(c);
        for(int i=0;i<n;i++) {
            if(isalpha(s[i])) s[i]=st.top(), st.pop();
        }
        return s;
    }
};


