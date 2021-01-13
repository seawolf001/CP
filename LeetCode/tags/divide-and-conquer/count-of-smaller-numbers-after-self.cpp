
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef vector<pair<int, int>> vpii;
    vector<int> inversions;
    vpii numsIdx, merged;

    void countInversionsInMerge(int l, int m, int r) {
        int i=l, j=m+1, k=l;
        while(i<=m) {
            while((j<=r && numsIdx[i].first > numsIdx[j].first)) j++;
            inversions[numsIdx[i].second] += j-(m+1);
            i++;
        }
        i=l, j=m+1;
        while(i<=m && j<=r) {
            if(numsIdx[i].first > numsIdx[j].first) {
                merged[k++] = numsIdx[j++];
            } else {
                merged[k++] = numsIdx[i++];
            }
        }
        while(i<=m) merged[k++] = numsIdx[i++];
        while(j<=r) merged[k++] = numsIdx[j++];
        for(int x=l;x<=r;x++) numsIdx[x]=merged[x];
    }

    void mergesort(int l, int r) {
        if(l>=r) return;
        int m=(l+r)/2;
        mergesort(l,m);
        mergesort(m+1,r);
        countInversionsInMerge(l,m,r);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return {};
        inversions = vector<int>(n,0);
        numsIdx = vpii(n);
        merged = vpii(n);
        for(int i=0;i<n;i++) numsIdx[i]= make_pair(nums[i],i);
        mergesort(0,n-1);
        return inversions;
    }
};


