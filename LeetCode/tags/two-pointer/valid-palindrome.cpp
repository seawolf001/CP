#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size(), i=0, j=n-1;
        while(i<j) {
            if(!isalnum(s[i])) { i++; continue; }
            if(!isalnum(s[j])) {j--; continue; }
            if(tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};

