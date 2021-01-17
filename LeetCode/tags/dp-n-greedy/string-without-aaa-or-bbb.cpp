#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {

public:
    string strWithout3a3b(int a, int b) {
        string ans="";
        while(a && b) {
            if(a>b) {
                ans += "aab";
                a -= 2; --b;
            } else if(b>a) {
                ans += "bba";
                b -= 2; --a;
            } else {
                ans += "ab";
                --a; --b;
            }
        }
        if(a>0) ans += string(a, 'a');
        if(b>0) ans += string(b, 'b');
        return ans;
    }
};


