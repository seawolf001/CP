#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size(); //k = k % n;
        vi ans(n,0);
        if(k==0)
            return ans;
        else if(k>0) {
            for(int i=0;i<n;i++) {
                int sum=0, count=0, j=i+1;
                while(++count <= k) sum += code[j % n], ++j;
                ans[i] = sum;
            }
        } else {
            for(int i=n-1;i>=0;i--) {
                int sum=0, count=0, j=i-1;
                while(++count <= -k) sum += code[(j+n)%n], --j;
                ans[i] = sum;
            }
        }
        return ans;
    }
};


