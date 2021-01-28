
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
    bool helper(string s, int p, int q, int r, vector<int> &ans) {
        string a = s.substr(p, q-p),
               b = s.substr(q, r-q),
               c = "";
        if((a.size()>1 && a[0]=='0') || (b.size()>1 && b[0]=='0'))
            return false;
        long x = stoll(a), y = stoll(b), z=0;
        int idx = r;
        while(++idx <= s.size()) {
            c = s.substr(r, idx-r);
            z = stoll(c);
            if(z >= x+y) break;
        }
        if((c.size()>1 && c[0]=='0') || z != x+y)
            return false;
        ans.push_back(x);
        if(idx >= s.size()) {
            // otherwise the last 2 numbers out of three are
            // propagated to next recursion call.
            // ex: a b c, b c d, c d e
            ans.push_back(y);
            ans.push_back(z);
            return true;
        }
        return helper(s, q, r, idx, ans);
    }
public:
    vector<int> splitIntoFibonacci(string s) {
        int n = s.size();
        if(n < 3) return {};
        int s0 = s[0]-'0', s1 = s[1]-'0', s2 = s[2]-'0';
        if(n==3 && s0+s1==s2) return {s0,s1,s2};
        // for > 3
        for(int i=1;i <n-2;i++) {
            for(int j=i+1;j<n-1;j++) {
                vector<int> ans;
                if(helper(s, 0, i, j, ans))
                    return ans;
            }
        }
        return {};
    }
};

