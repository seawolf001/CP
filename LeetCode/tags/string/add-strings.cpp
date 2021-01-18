#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n=num1.size(), m=num2.size(), carry=0, s=0;
        string ans="";
        while(n||m||carry) {
            s = carry;
            if(n>0) s += num1[n-1]-'0', --n;
            if(m>0) s += num2[m-1]-'0', --m;
            ans = to_string(s%10) + ans;
            carry = s/10;
        }
        return ans;
    }
};


