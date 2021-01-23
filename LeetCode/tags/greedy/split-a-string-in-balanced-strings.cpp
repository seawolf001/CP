#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int balancedStringSplit(string s) {
        int count=0, ans=0;
        for(char &c:s) {
            if(c=='L')
                ++count;
            else
                --count;
            if(count==0)
                ++ans;
        }
        return ans;
    }
};


