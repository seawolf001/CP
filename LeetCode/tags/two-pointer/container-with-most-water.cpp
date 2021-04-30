#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l=0,h=n-1, ans=INT_MIN, curr=0;
        while(l<h) {
            curr = (height[l]<height[h] ? height[l++]:height[h--]) * (h-l+1);
            ans = max(ans, curr);
        }
        return ans;
    }
};


