#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count=0, n=arr.size();
        for(int k=2;k<n;k++) {
            for(int j=1;j<k;j++) {
                for(int i=0;i<j;i++) {
                    if(abs(arr[i]-arr[j])<=a &&
                       abs(arr[j]-arr[k])<=b &&
                       abs(arr[k]-arr[i])<=c)
                        ++count;
                }
            }
        }
        return count;
    }
};
