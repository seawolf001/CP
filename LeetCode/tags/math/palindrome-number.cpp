/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long N=0, M=x;
        while(x>0) {
            N = N * 10 + x%10;
            x /= 10;
        }
        return N==M;
    }
};


