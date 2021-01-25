#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    int AtMostK(vector<int>&A, int K) {
        int res=0, i=0,j=0, n=A.size(), cnt=0;
        if(K==0)  return 0;
        unordered_map<int, int> freq;
        for(;j<n;j++) {

            if(freq[A[j]]==0) // new number introduced in the window
                ++cnt;
            ++freq[A[j]];

            while(i<j && cnt > K) { // cnt should be atmost K
                --freq[A[i]]; // discard the i-th number
                if(freq[A[i]]==0)
                    --cnt;
                ++i;
            }

            res += j-i+1; // for [i...j], j-i+1 subarrays with atmost K diff numbers.
        }
        return res;
    }
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return AtMostK(A,K) - AtMostK(A, K-1);
    }
};

