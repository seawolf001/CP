#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

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
