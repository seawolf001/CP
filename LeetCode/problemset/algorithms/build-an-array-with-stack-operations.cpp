/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> st;
        int t=0, i=1;
        while(i<=n) {
            if(t==target.size()) break;
            if(target[t]==i) {
                t++;
                st.push_back("Push");
            } else {
                st.push_back("Push"); st.push_back("Pop");
            }
            i++;
        }
        return st;
    }
};


