#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

#include<bits/stdc++.h>
// https://leetcode.com/problems/longest-mountain-in-array/
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int longest = 0;
        int n = arr.size(), i=1;
        while(i < n-1) {
            if(false==(arr[i-1]<arr[i] && arr[i]>arr[i+1])) {
                i++;
                continue;
            }
            int left = i-2, right=i+2;
            while (left >= 0 && arr[left] <  arr[left+1]) left--;
            while (right < n && arr[right] < arr[right-1]) right++;
            longest = max(longest, right-left-1);
            i = right;
        }
        return longest;
    }
};
