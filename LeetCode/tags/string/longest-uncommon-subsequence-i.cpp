#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;


class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a==b)
            return -1;
        return max(a.size(),b.size());
    }
};
