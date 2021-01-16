#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long l=1,r=n,m=0,g=0;
        while(l<=r) {
            m = (l+r)/2; g = guess(m);
            if(g==0) return m;
            else if(g==1) l=m+1;
            else r=m-1;
        }
        return l;
    }
};


