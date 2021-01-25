#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size(), count=0;
        for(int i=0;i<n-K+1; i++) {
            unordered_set<int> s;
            for(int j=i;j<n;j++) {
                s.insert(A[j]);
                if(s.size()==K) ++count;
                else if(s.size()>K) break;
            }
        }
        return count;
    }
};


