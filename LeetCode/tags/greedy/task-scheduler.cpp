#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

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
        return max((n-(c-1)) * (F-1) + c * F , N);
    }
};


