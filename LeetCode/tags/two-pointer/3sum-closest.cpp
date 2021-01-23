#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int threeSumClosest(vector<int>& v, int target) {
        int n = v.size();
        sort(v.begin(), v.end());
        int ans = v[0]+v[1]+v[2], sum=0;
        for(int i=0;i<n-2;i++) {
            int j = i+1, k = n-1;
            while(j<k) {
                // cout << nums[i] << " " << nums[j] << " " << nums[k] << endl;
                sum = v[i]+v[j]+v[k];
                if(abs(target-sum) < abs(target-ans)) {
                    ans = sum;
                    if(ans==target)
                        return ans;
                }
                sum < target ? ++j : --k;
            }
        }
        return ans;
    }
};


