#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int ans=0, lmax=INT_MIN, rmax=INT_MIN, l=0,h=n-1;
        while(l<=h) {
            if(arr[l] < arr[h]) {
                if(arr[l] > lmax)
                    lmax = arr[l];
                else
                    ans += lmax-arr[l];
                ++l;
            } else {
                if(arr[h] > rmax)
                    rmax = arr[h];
                else
                    ans += rmax-arr[h];
                --h;
            }
        }
        return ans;
    }
};

