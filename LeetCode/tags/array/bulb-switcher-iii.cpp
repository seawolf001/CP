#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int n = light.size(), res=0, ones=0,twos=2;
        map<int, int> tracker;
        for(int b: light) {
            int x=b,y=b;
            tracker[b] = b==1||tracker[b-1]==2 ? 2 : tracker[b] == 0 ? 1 : tracker[b];
            if(tracker[b]==1) ++ones;
            else ++twos;
            while(tracker[b]==2 && ++y<=n && tracker[y]==1)
                tracker[y]=2, --ones, ++twos;
            if(twos>0 && ones==0) ++res;
        }
        return res;
    }
};


