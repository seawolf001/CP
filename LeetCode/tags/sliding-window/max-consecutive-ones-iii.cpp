#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n=A.size(),i=0,j=0,cnt=0, res=-1;
        for(;j<n;j++) {
            if(A[j]==0) ++cnt;
            while(i<j && cnt>K) {
                if(A[i]==0) --cnt;
                ++i;
            }
            if(cnt <= K) res = max(res, j-i+1);
        }
        if(res == -1) res = cnt <= K ? n : 0; // if zeroes <= K turn them all to 1
        return res;
    }
};


