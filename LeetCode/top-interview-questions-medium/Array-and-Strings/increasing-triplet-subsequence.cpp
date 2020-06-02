
/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n<3) return false;
        int * smaller = new int[n];
        smaller[0] = INT_MIN;
        int MIN = nums[0];
        for(int i=1;i<n;i++) {
            if(nums[i] <= MIN) {
                MIN = nums[i];
                smaller[i] = INT_MIN;
            } else {
                smaller[i] = MIN;
            }
        }
        int * greater = new int[n];
        greater[n-1] = INT_MAX;
        int MAX = nums[n-1];
        for(int i=n-2; i>=0; i--) {
            if(nums[i] >= MAX) {
                MAX = nums[i];
                greater[i] = INT_MAX;
            } else {
                greater[i] = MAX;
            }
        }
        bool triplet_exists = false;
        for(int i=0;i<n;i++) {
            if (smaller[i] != INT_MIN && greater[i] != INT_MAX) {
                triplet_exists = true;
                break;
            }
        }
        delete[] smaller;
        delete[] greater;
        return triplet_exists;
    }
};

// int main() {
//     Solution s;
//     vector<int> v {1,2,3,4,5};
//     cout << s.increasingTriplet(v) << endl;
// }

