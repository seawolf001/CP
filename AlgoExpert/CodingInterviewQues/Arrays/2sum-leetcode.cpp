/* Jitendra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

/*
 * Using two for loops and iterate through each combination: O(n^2) Time | O(1) Space
 * Using a map, for every x, lookup for target-x: O(n) Time | O(n) Space
 * Sort and use Two pointer technique: O(nlogn) Time | O(1) Space
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*Because indices are to be returned, using hashing method*/
        unordered_map<int, int> hash;
        for(int i=0;i<nums.size(); i++) {
            if(hash.find(target-nums[i])!=hash.end())
                return {i, hash[target-nums[i]]};
            hash[nums[i]] = i;
        }
        return {};
    }
};
