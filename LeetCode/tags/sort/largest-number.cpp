#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.size()==1) return to_string(nums[0]);
        string ans="";
        unordered_map<int, string> ts;
        sort(nums.begin(), nums.end(), [&](const int x, const int y) {
                                if(x==0 && y==0) return false; // patch
                                if(ts.count(x)==0) ts[x]=to_string(x);
                                if(ts.count(y)==0) ts[y]=to_string(y);
                                return ts[x]+ts[y] >= ts[y]+ts[x];
                        });
        if(nums[0]==0)
            return "0";
        for(int &x:nums)  ans += ts[x];
        return ans;
    }
};


