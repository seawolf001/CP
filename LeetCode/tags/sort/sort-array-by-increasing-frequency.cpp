#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> f;
        for(int &x: nums) f[x]++;
        sort(nums.begin(), nums.end(), [&](const int &a, const int &b){
                                            if(f[a]==f[b])
                                                return a > b;
                                            return f[a] < f[b];
                                        });
        return nums;
   }
};


