#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(); int maxp=INT_MIN;
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                maxp = max(maxp, (nums[i]-1)*(nums[j]-1));
            }
        }
        return maxp;
    }
};


