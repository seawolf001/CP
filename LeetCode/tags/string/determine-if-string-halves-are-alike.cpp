#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size(), c=0;
        unordered_set<char> vowels{'a','e','i','o','u','A','E','I','O','U'};
        for(int i=0;i<n/2;i++) {
            if(vowels.count(s[i])!=0) ++c;
        }
        for(int i=n/2;i<n;i++) {
            if(vowels.count(s[i])!=0) --c;
        }
        return c==0;
    }
};


