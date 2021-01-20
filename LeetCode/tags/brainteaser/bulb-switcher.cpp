#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

/*
 N will afftected i in one of its factors.
 If N has ODD number of factors --> remains ON after nth round.
 else remains OFF after nth round.


All numbers has even number of factors (in pairs, (1,n), (2,n/2), (3,n/3).. etc)
But perfect squares have OFF number of factores because i*i=n so one less factor.


Basically, all the numbers <= n which are perfect squares, i.e. sqrt(n), remain ON.
 * */

class Solution {
public:
    int bulbSwitch(int n) {
        return (int)(sqrt(n));
    }
};
