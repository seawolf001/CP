#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    vector<vector<int>> ans;
    void solver(vector<int>& candidates, int idx, int target, int sum, vector<int> &curr){
        if(idx >= candidates.size()) return;
        if(sum == target) { ans.push_back(curr); return; }
        while(idx < candidates.size() && candidates[idx] > target-sum) ++idx;
        if(idx >= candidates.size()) return;
        curr.push_back(candidates[idx]);
        solver(candidates, idx, target, sum + candidates[idx], curr);
        curr.pop_back();
        solver(candidates, idx+1, target, sum, curr);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear(); vector<int> curr;
        solver(candidates, 0, target, 0, curr);
        return ans;
    }
};


