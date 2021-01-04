/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int N = tasks.size();
        if(n==0) return N;
        int f[26]={0};
        int F=0, c=0;
        for(char c:tasks) {
            f[c-'A']++;
            F = max(F, f[c-'A']);
        }
        for(int x:f) {
            if(x==F) c++;
        }
        return max((F - 1) * n + F + c - 1, N);
    }
};

