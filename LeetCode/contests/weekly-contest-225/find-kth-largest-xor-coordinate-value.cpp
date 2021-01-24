#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& arr, int k) {
        int n = arr.size(), m = n>0 ? arr[0].size() : 0, i=0, j=0;
        priority_queue<int, vector<int>, greater<int>> minh;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i==0 && j==0) arr[i][j]=arr[i][j];
                else if(i==0) arr[i][j] ^= arr[i][j-1];
                else if(j==0) arr[i][j] ^= arr[i-1][j];
                else arr[i][j] ^= (arr[i-1][j] ^ arr[i][j-1] ^ arr[i-1][j-1]);
                minh.push(arr[i][j]);
                if(minh.size() > k) minh.pop();
                // cout << arr[i][j] << " ";
            }
            // cout << endl;
        }
        return minh.top();
    }
};

