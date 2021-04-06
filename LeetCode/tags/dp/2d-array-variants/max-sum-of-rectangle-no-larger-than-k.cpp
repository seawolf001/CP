#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    int kadane_sum(vector<int> &v) {
        int curr=v[0], maxs=v[0];
        for(int i=1;i<v.size(); i++) {
            curr = max(v[i], curr+v[i]);
            maxs = max(maxs, curr);
        }
        return maxs;
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& arr, int k) {
        int n = arr.size(), m = n>0 ? arr[0].size() : 0, result = INT_MIN;
        for(int l=0;l<m;l++) {
            vector<int> summ(n,0);
            for(int r=l;r<m;r++) {
                int curr=0, maxs=INT_MIN;
                for(int i=0;i<n;i++) {
                    summ[i] += arr[i][r];
                    curr = max(summ[i], curr+summ[i]);
                    maxs = max(maxs, curr);
                }
                int kadane = maxs;
                if(kadane <= k) {
                    result = max(result, kadane);
                } else {
                    // need to select another subarray not the one kadane gives
                    // This should be as close as possible to kadane sum
                    set<int> s={0}; curr = 0;
                    for(int x: summ) {
                        curr += x;
                        auto it = s.lower_bound(curr-k);
                        if(it != s.end())
                            result = max(result, curr-*it);
                        s.insert(curr);
                    }
                }
            }
        }
        return result;
    }
};


