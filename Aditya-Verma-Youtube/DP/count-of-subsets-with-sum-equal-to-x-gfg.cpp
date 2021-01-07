/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

int subsets_count(vector<int>& nums, int S) {
    vector<int> dp(S+1, 0);
    dp[0]=1;
    for(int &num: nums) {
        for(int s=S; s>=num; s--) {
            dp[s] += dp[s-num];
        }
    }
    return dp[S];
}

int main() {
    vector<int> v;
    v.assign({1, 2, 3, 3}); assert (subsets_count(v, 6)==3);
    v.assign({1, 1, 1, 1}); assert (subsets_count(v, 1)==4);
    v.assign({3, 3, 3, 3}); assert (subsets_count(v, 6)==6);
    cout << "All tests passing." << endl;
    return 0;
}
