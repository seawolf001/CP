#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
    bool all_zero(vector<int> &f) {
        for(int &x: f)
            if(x!=0)
                return false;
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n1 > n2)
            return false;
        vector<int> f(26,0);
        for(int i=0;i < n1;i++) {
            f[s1[i]-'a']--;
            f[s2[i]-'a']++;
        }
        if(all_zero(f))
            return true;
        for(int i=n1;i<n2;i++) {
            // slide the window now and check for each window
            f[s2[i]-'a']++;
            f[s2[i-n1]-'a']--;

            if(all_zero(f))
                return true;
        }
        return false;
    }
};


