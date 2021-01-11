/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(), next=0;
        vector<int> ng(n, -1);
        stack<int> st;
        for(int i=0;i<2*n;i++) {
            next = nums[i%n];
            while(!st.empty() && nums[st.top()]<next) {
                ng[st.top()]=next; // key-->value, key is index
                st.pop();
            }
            if(i<n) st.push(i); // use indices
        }
        return ng;
    }
};

/*
1 2 1 1 2 1
2 -1 2 2 -1 2

3  2 1  3  2  1
-1 3 3

*/
