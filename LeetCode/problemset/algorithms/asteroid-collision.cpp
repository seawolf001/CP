/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& x) {
        vector<int> res;
        int n=x.size();
        for(int i=0;i<n;i++) {
            if(x[i]>0) {
                res.push_back(x[i]);
            } else {
                while(res.size()>0 && res.back()>0 && abs(res.back()) < abs(x[i])) {
                    res.pop_back();
                }
                if(res.size()==0 || res.back()<0) res.push_back(x[i]);
                else if(abs(res.back()) == abs(x[i])) res.pop_back();
            }
        }
        return res;
    }
};


