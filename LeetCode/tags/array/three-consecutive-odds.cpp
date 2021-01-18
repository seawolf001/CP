#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i=2;i<arr.size();i++) {
            if(arr[i-2]&1==1 && arr[i-1]&1==1 && arr[i]&1==1)
                return true;
        }
        return false;
    }
};


