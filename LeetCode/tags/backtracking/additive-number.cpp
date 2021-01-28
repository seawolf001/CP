#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    // check for p..q, q..r, r..size
    bool helper(string s, int p, int q, int r) {
        string a = s.substr(p, q-p),
               b = s.substr(q, r-q),
               c = "";
        if((a.size()>1 && a[0]=='0') || (b.size()>1 && b[0]=='0'))
            return false;
        long x = stol(a), y = stol(b), sum=0;
        int idx = r;
        while(++idx <= s.size()) {
            c = s.substr(r, idx-r);
            sum = stol(c);
            if(sum >= x+y) break;
        }
        if((c.size()>1 && c[0]=='0') || sum != x+y)
            return false;
        if(idx >= s.size() || helper(s, q, r, idx))
            return true;
        return false;
    }
public:
    bool isAdditiveNumber(string s) {
        int n = s.size();
        if(n< 3)
            return false;
        else if(n==3)
            return (s[2]-'0' == (s[0]-'0') + (s[1]-'0'));
        // for > 3
        for(int i=1;i<n-2;i++) {
            for(int j=i+1;j<n-1;j++) {
                if(helper(s, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};

