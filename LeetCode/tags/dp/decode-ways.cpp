#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n==0 || s[0]=='0')
            return 0;
        int len2=1, len1=1;
        for(int i=1;i<n;i++) {
            int x = s[i]-'0', y = stoi(s.substr(i-1,2)), z=0;
            if(1<=x && x<=9)
                z += len1;
            if(10<=y && y<=26)
                z += len2;
            len2 = len1;
            len1 = z;
        }
        return len1;
    }
};

