
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l=0,r=0,n=weights.size();
        for(int i=0;i<n;i++) {
            r += weights[i];
            l = max(l,weights[i]);
        }
        // The smallest capacity (l) is the weight of the largest package
        // cannot be less than r / D
        l = max(l, r/D);
        while(l<r) {
            int m = (l+r)/2; // current capacity
            int curr=0, days=1;
            for(int& x: weights) {
                curr+=x;
                if(curr>m) {
                    days++;
                    curr=x;
                }
            }
            // cout << "l="<<l<<" m="<<m<<" r="<<r<<" days="<<days<<endl;
            if(days<=D) r=m; // found but can we do better?
            else l=m+1;
        }
        return l;
    }
};
