#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int minSubArrayLen(int S, vector<int>& nums) {
        int n = nums.size(), i=0, j=0, curr=0, res=INT_MAX;
        for(;j<n;j++) {
            curr += nums[j];
            while(i<=j && curr >= S) {
                res = min(res, j-i+1);
                curr -= nums[i]; ++i;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

