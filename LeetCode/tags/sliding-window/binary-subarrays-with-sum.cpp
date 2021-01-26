#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    int atMost(vector<int>&A, int sum) {
        int  n = A.size(), i=0,j=0,res=0, curr=0;
        for(;j<n;j++) {
            curr += A[j];
            while(i<j && curr > sum) {
                curr -= A[i];
                ++i;
            }
            if(curr<=sum) res += j-i+1;
        }
        return res;
    }
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        return atMost(A,S) - atMost(A,S-1);
    }
};

