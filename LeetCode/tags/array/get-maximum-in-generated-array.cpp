#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int getMaximumGenerated(int n) {
        vi arr(n+2,0); arr[1]=1;
        for(int i=1;i<=n/2;++i) {
            arr[2*i] = arr[i];
            arr[2*i+1] = arr[i]+arr[i+1];
        }
        return *max_element(arr.begin(), --arr.end());
    }
};


