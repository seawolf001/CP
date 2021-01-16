#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;
        for(int i=0;i<numbers.size();i++) {
            if(mp.find(target-numbers[i])!=mp.end()) {
                int j=mp[target-numbers[i]];
                if(i<j)
                    return {i+1,j+1};
                return {j+1,i+1};
            }
            mp[numbers[i]]=i;
        }
        return {};
    }
};


