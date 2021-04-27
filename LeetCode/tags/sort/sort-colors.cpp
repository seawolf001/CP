#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l=0,m=0,h=n-1;
        while(m<=h) {
            switch(nums[m]) {
                case 0:
                    swap(nums[l++],nums[m++]);
                    break;
                case 1:
                    m++;
                    break;
                case 2:
                    swap(nums[m], nums[h--]);
                    break;
            }
        }
    }
};
