#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int minimumTotal(vector<vector<int>>& tr) {
        int n = tr.size();
        int ans = INT_MAX;
        for(int i=1;i<n;++i) {
            int m = tr[i].size();
            for(int j=0;j<m;++j) {
                int x = j-1 >= 0 ? tr[i][j] + tr[i-1][j-1]: INT_MAX;
                int y = j !=m-1 ? tr[i][j] + tr[i-1][j]: INT_MAX;
                tr[i][j]  = min({x, y});
            }
        }
        return *min_element(tr[n-1].begin(), tr[n-1].end());
    }
};


