/* Jitendra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

/* O(n) Time | O(1) Space*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), index=0;
        for(int i=0;i<n;i++) {
            if(nums[i] != val) nums[index++] = nums[i];
        }
        // for(int i=index;i<n;i++) nums[i]=val; // Move all instances of val to last.
        return index;
    }
};

