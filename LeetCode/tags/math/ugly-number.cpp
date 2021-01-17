#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    bool isUgly(int num) {
        if(num==0) return false;
        while(num % 5 == 0) num/=5;
        while(num % 3 == 0) num/=3;
        while(num % 2 == 0) num/=2;
        return num==1;
    }
};


