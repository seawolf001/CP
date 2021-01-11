/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

/*
rob(i) = Math.max( rob(i - 2) + currentHouseValue, rob(i - 1) )

1.Find recursive relation
2.Recursive (top-down)
3.Recursive + memo (top-down)
4.Iterative + memo (bottom-up)
5.Iterative + N variables (bottom-up)
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0;
        int prev2 = 0;
        for (int num : nums) {
            int tmp = prev1;
            prev1 = max(prev2 + num, prev1);
            prev2 = tmp;
        }
        return prev1;
    }
};

