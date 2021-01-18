#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    int maxPower(string s) {
        int maxp=INT_MIN; char prev='\0'; int cnt=1;
        for(char &c:s) {
            if(c!=prev) {
                maxp = max(maxp, cnt);
                prev=c;
                cnt=1;
            } else {
                ++cnt;
            }
        }
        return max(maxp, cnt);;
    }
};


