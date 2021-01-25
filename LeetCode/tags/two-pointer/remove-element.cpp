#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

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


