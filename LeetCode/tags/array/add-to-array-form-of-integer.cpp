#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(A.begin(), A.end()); int carry=0, d=0, s=0;
        for(auto &x:A) {
            d = K % 10; K = K/10;
            s = x + carry + d;
            x = s % 10;
            carry = s / 10;
        }
        while (K>0) {
            d = K % 10; K = K/10;
            s = carry + d;
            A.push_back(s % 10);
            carry = s/10;
        }
        if(carry > 0) A.push_back(carry);
        reverse(A.begin(), A.end());
        return A;
    }
};


