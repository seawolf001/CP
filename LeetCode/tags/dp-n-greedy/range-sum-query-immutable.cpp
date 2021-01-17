
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class NumArray {
private:
    vector<long> dp={0};
public:
    NumArray(vector<int>& nums) {
        long s=0;
        for(int x:nums) {
            s+=x;
            dp.push_back(s);
        }
        for(int x:dp) cout << x << " ";
    }

    int sumRange(int i, int j) {
        return dp[j+1]-dp[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
