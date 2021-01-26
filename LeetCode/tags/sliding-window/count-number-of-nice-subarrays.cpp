#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    int AtMost(vector<int>& nums, int k) {
        int n=nums.size(), i=0,j=0,res=0,cnt=0;
        for(;j<n;j++) {
            if(nums[j] & 1) ++cnt;
            while(i<=j && cnt>k) {
                if(nums[i] & 1) --cnt;
                ++i;
            }
            res += j-i+1;
        }
        return res;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return AtMost(nums, k) - AtMost(nums, k-1);
    }
};


