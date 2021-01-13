
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        int left[n], right[n];
        memset(left, 0, sizeof(left)); memset(right, 0, sizeof(right));
        stack<pair<int, int>> st;
        for(int i=0;i<n;i++) {
            int c=1;
            while(!st.empty() && st.top().first>=A[i]) {
                c += st.top().second;
                st.pop();
            }
            st.push(make_pair(A[i], c));
            left[i]=c;
        }
        st={};
        for(int i=n-1;i>=0;i--) {
            int c=1;
            while(!st.empty() && st.top().first>A[i]) {
                c += st.top().second;
                st.pop();
            }
            st.push(make_pair(A[i], c));
            right[i]=c;
        }
        int res=0;
        for (int i = 0; i < n; ++i)
            res = (res + ((long)A[i] * left[i] * right[i]) % MOD) % MOD;
        return res;
    }
};




