#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int nextGreaterElement(int N) {
        string digits = to_string(N);
        int n = digits.size();
        int i,j;
        for(i=n-1;i>0;i--) {
            if(digits[i-1] < digits[i])
                break;
        }
        if(i==0) return -1;
        int x = digits[i-1], smallest = i;
        for(j=i+1;j<n;j++) {
            if(digits[j] > x && digits[j] < digits[smallest])
                smallest = j;
        }
        swap(digits[i-1], digits[smallest]);
        sort(digits.begin()+i, digits.end());
        long long ans = stoll(digits);
        return ans <= INT_MAX ? (int) ans : -1;
    }
};


