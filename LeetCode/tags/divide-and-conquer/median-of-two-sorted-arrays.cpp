
#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        // nums1 would be the smaller one.
        int lo = 0, hi = n1;
        while(lo <= hi) {
            int cut1 = (lo + hi)/2;
            int cut2 = (n1+n2)/2 - cut1;
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            int r1 = cut1 == n1 ? INT_MAX: nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX: nums2[cut2];
            // condition: l1 < r2 && l1 < r1
            if(l1 > r2) hi = cut1-1;
            else if(l2 > r1) lo = cut1 + 1;
            else {
                if((n1+n2) % 2 == 0)
                    return (max(l1,l2) + min(r1,r2))/2.0;
                else
                    return min(r1,r2); // since one extra element in right partition
            }
        }
        return -1;
    }
};




