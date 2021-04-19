#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int l=0, h=n-1, x, y, idx=n-1;
        while(l<=h) {
            x = nums[l] * nums[l];
            y = nums[h] * nums[h];
            if(x > y)
                res[idx--] = x, ++l;
            else
                res[idx--] = y, --h;
        }
        return res;
    }
};


