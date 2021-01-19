#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> hs(candyType.begin(), candyType.end());
        return min(hs.size(), candyType.size()/2);
    }
};
