#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), pos=n-1;
        if(n==1) return true;
        for(int i=n-1;i>=0;i--) {
            if(nums[i]+i >= pos)
                pos = i; // able to reach "pos" from i, lets see if can reach "i".
        }
        return pos==0;
    }
};


