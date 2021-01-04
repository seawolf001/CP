/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int findNthDigit(int n) {
        long i=0, t=n, t1=0, res=0, num=0;
        while(t>0) {
            t1 = t;
            t -= 9*pow(10, i)*(i+1);
            i++;
        }
        t = t1;
        // i ==> number of digits
        int q, r;
        q = t/i;
        r = t%i;
        if(r==0) {
            num = pow(10, i-1) + q-1;
            res = num % 10;
        } else {
            num = pow(10, i-1) + q;
            int x=i-r;
            while(x--) {
                num /= 10;
            }
            res = num % 10;
        }
        return res;
    }
};

