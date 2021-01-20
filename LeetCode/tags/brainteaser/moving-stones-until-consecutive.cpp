#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int>v{a,b,c}; sort(v.begin(),v.end()); a=v[0], b=v[1], c=v[2];
        int minx=INT_MAX, maxx=INT_MAX;
        if(c-a==2) minx=0;
        else if(b-a<=2||c-b<=2) minx=1;
        return {min(2,minx), c-a-2};
    }
};
