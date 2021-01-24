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
        int n = nums1.size(),m=nums2.size();
        int k = m+n, c=-1, x=0,y=0, i=0,j=0;
        while(i<n && j<m && c!=k/2) {
            if(nums1[i]<nums2[j]) y=x, x = nums1[i], ++i;
            else y=x, x=nums2[j], ++j;
            ++c;
        }
        while(c<k/2 && i<n) y=x, x=nums1[i], ++c, ++i;
        while(c<k/2 && j<m) y=x, x=nums2[j], ++c, ++j;
        cout << x << " " << y << endl;
        if(k%2==1) return x;
        return (double)(x+y)/2;
    }
};
