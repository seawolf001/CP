
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int N) {
        int count=0;
        int n = arr.size();
        for(int i=0;i<n;i++) {
            int l = i-1>=0 ? arr[i-1] : 0;
            int r = i+1<n ? arr[i+1] : 0;
            if(l||r||arr[i]) continue;
            arr[i]=1;
            if(++count>=N) return true;
        }
        return count>=N;
    }
};


