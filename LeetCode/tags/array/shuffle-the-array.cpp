#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n,0); int i=0,j=n; int flag=true, k=0;
        while(i<n||j<2*n) {
            if(flag) ans[k++] = nums[i++];
            else ans[k++] = nums[j++];
            flag = !flag;
        }
        return ans;
    }
};


