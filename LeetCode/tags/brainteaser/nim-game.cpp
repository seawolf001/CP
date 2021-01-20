#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

/*
 n=1, wins
 n=2, wins
 n=3, wins,
 n=4, removing any of {1,2,3}, atleast 1 stone remains and you LOSE.
 n=5, remove 1 and the other person will lose for n=4
 .....and so on.

 by induction, for n%4==0, you lose and for others you win.
 * */
class Solution {
public:
    bool canWinNim(int n) {
        return n%4!=0;
    }
};
