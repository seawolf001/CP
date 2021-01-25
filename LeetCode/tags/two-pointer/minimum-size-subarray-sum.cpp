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
        int n = nums.size();
        if(n==0) return 0;
        int curr=0, L=INT_MAX, s=0,e=-1;
        while(e < n-1) {
            // subarray to be [s..e] inclusive
            curr += nums[++e];
            while(e < n-1 && curr < S) {
                curr += nums[++e];
            }
            while(s < n && s <= e && curr-nums[s]>=S) {
                curr -= nums[s++];
            }
            if(curr >= S) L = min(L, e-s+1);
        }
        return L == INT_MAX ? 0 : L;
    }
};

