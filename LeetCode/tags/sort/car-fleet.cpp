#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int carFleet(int T, vector<int>& ps, vector<int>& speed) {
        map<int, double, greater<int>> mp;
        int n = ps.size(); int ans=0; double t=-1;
        for(int i=0;i<n;i++){
            // cout << ps[i] << " " << speed[i] << " " << ((T-ps[i])*1.0/speed[i]) << endl;
            mp[ps[i]]= (double) ((T-ps[i])*1.0/speed[i]);
        }
        for(auto &e:mp) if(e.second > t) ++ans, t=e.second;
        return ans;
    }
};


