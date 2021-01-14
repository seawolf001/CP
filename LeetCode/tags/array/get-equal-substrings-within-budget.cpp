
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        if(n==0) return 0;
        int st=0,e=0,cost=0,L=0;
        while(e<n){
            cost += abs(s[e]-t[e++]);
            if(cost>maxCost) cost-=abs(s[st]-t[st++]);
        }
        return e-st;
    }
};


