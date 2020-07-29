
/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size(), i=0, j=n-1;
        while(i<j) {
            if(!isalnum(s[i])) { i++; continue; }
            if(!isalnum(s[j])) { j--; continue; }
            if(tolower(s[i]) != tolower(s[j])) return false;
            i++; j--;
        }
        return true;
    }
};

