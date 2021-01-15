#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi
typedef vector<vector<int>> vii

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size(), a=0,b=0, friendships=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                a = ages[i]; b = ages[j];
                if(i==j || b>a || 0.5*a+7 >= b || (b>100  && a<100)) continue;
                ++friendships;
            }
        }
        return friendships;
    }
};


