#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    //https://leetcode.com/problems/n-repeated-element-in-size-2n-array/discuss/208317/C%2B%2B-2-lines-O(4)-or-O-(1)
    int repeatedNTimes(vector<int>& A, int i = 0, int j = 0) {
        while (A[i = rand() % A.size()] != A[j = rand() % A.size()] || i == j);
        return A[i];
    }
};


