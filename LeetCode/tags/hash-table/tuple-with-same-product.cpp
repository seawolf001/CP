#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> ump;
        for(int i=0;i<n;i++)
            for(int j=0;j<i;j++)
                ump[nums[i]*nums[j]]++;
        long ans=0, c=0;
        for(auto &p:ump) {
            c = p.second;
            ans += ((c*(c-1))/2)*8; // nc2 * 8; nc2 for two pairs and 8 permutations for ((a,b),(c,d))
        }
        return ans;
    }
};


