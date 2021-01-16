#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(m>0 && n>0) {
            if(nums1[m-1] >= nums2[n-1]) nums1[n+m-1] = nums1[m-1], --m;
            else nums1[n+m-1] = nums2[n-1], --n;
        }
        while(m>0) nums1[n+m-1] = nums1[m-1], --m;
        while(n>0) nums1[n+m-1] = nums2[n-1], --n;
    }
};


