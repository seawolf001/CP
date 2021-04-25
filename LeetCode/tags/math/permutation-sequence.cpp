#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        string s = "";
        for(int i=1;i<n;i++) {
            fact *= i;
            s += to_string(i);
        }
        s += to_string(n);
        string ans = "";
        --k; // Kth nummber will be 0....k-1 th number in permutation sequence
        while(true) {
            int idx = k / fact;
            ans += s[idx];
            s.erase(idx, 1);
            if(s.size() == 0)
                break;
            k = k % fact;
            fact = fact / s.size();
            cout << idx << " " << k << " " << fact << endl;
        }
        return ans;
    }
};
