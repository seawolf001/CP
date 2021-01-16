#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        for(const int &x:s) {
            s.insert(x);
            if(s.size()>3)
                s.erase(s.begin());
        }
        return s.size()==3 ? *s.begin() : *s.rbegin();
    }
};


