#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int totalFruit(vector<int>& T) {
        int n = T.size(), i=0,j=0,res=INT_MIN;
        unordered_map<int, int> f;
        for(;j<n;j++) {
            f[T[j]]++;
            while(i<j && f.size()>2) {
                f[T[i]]--;
                if(f[T[i]]==0)
                    f.erase(T[i]);
                ++i;
            }
            if(f.size()<=2) res = max(res, j-i+1);
        }
        return res == INT_MIN ? n : res;
    }
};

