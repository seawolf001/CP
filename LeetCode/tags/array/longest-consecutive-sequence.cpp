#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(),  ans=1, curr=0;
        if(n==0) return 0;
        unordered_set<int> s;
        for(int x: nums)  s.insert(x);
        for(int x: nums) {
            int y = x+1;
            while(s.find(y) != s.end()) ++y;
            ans = max(ans, y-x);
        }
        return ans;
    }
};


