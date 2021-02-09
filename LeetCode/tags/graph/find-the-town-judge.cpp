#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> in(N+1,0), out(N+1,0);
        for(auto &e: trust)
            ++in[e[1]], ++out[e[0]];

        for(int i=1;i<=N;i++)
            if(in[i]==N-1 && out[i]==0)
                return i;
        return -1;
    }
};




