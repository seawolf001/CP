
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
private:
    bool AP_nlogn(vector<int>& arr) {
        int n = arr.size();
        if(n<=2) return true;
        sort(arr.begin(), arr.end());
        int d = arr[1]-arr[0];
        for(int i=2;i<n;i++) {
            if(arr[i]-arr[i-1]!=d) return false;
        }
        return true;
    }
    bool AP_n(vector<int>& arr) {
        int n = arr.size();
        if(n<=2) return true;
        int mx=INT_MIN, mn=INT_MAX;
        for(int i=0;i<n;i++) {
            mx = max(mx, arr[i]);
            mn = min(mn, arr[i]);
        }
        // AP: a, a+d, a+2d, ...., a+(n-1)d
        int d = (mx-mn)/(n-1);  // d = a+(n-1)d - a
        unordered_set<int> s(arr.begin(), arr.end());
        for(int i=0;i<n;i++) {
            if(s.find(mn+i*d)==s.end()) return false;
        }
        return true;
    }
public:
    bool canMakeArithmeticProgression(vector<int>& arr){
        return AP_n(arr);
    }
};
