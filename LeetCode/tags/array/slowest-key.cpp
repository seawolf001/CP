#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n=releaseTimes.size(); int maxx=releaseTimes[0]; char c=keysPressed[0];
        for(int i=n-1;i>0;i--) releaseTimes[i] -= releaseTimes[i-1];
        for(int i=1;i<n;i++) {
            if(releaseTimes[i]>maxx) {
                c = keysPressed[i];
                maxx = max(releaseTimes[i], maxx);
            } else if(releaseTimes[i]==maxx) {
                c = max(c, keysPressed[i]);
            }
        }
        return c;
    }
};


