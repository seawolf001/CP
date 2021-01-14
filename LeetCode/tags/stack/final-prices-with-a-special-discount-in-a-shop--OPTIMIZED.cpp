
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        if(n<2) return prices;
        stack<int> st;
        for(int i=0;i<n;i++) {
            while(!st.empty() && prices[st.top()]>=prices[i]) {
                prices[st.top()]-=prices[i];
                st.pop();
            }
            st.push(i);
        }
        return prices;
    }
};

