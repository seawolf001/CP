/* Jitendra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
private:
    int N=0;
    void helper(vector<int> &nums, int idx, vector<vector<int>> &result) {
        if(idx==N-1) {
            for(auto i=nums.begin();i!=nums.end();i++) cout << *i << " "; cout << endl;
            result.push_back(nums);
            return;
        }
        for(int i=idx;i<N;i++) {
            swap(nums[idx], nums[i]);
            helper(nums, idx+1, result);
            swap(nums[idx], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        N = nums.size();
        helper(nums, 0, result);
        return result;
    }
};

int main() {
    vector<int> nums{1,2,3};
    Solution s;
    s.permute(nums);
}
