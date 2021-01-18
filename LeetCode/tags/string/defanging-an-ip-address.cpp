#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    string defangIPaddr(string address) {
        string ans="";
        for(char &c:address) {
            if(c=='.') ans += "[.]";
            else ans += c;
        }
        return ans;
    }
};
