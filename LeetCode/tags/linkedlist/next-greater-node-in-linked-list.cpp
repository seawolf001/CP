#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    int length(ListNode* head) {
        int n = 0;
        while(head) ++n, head=head->next;
        return n;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if(!head) return {};
        else if(!head->next) return {0};
        ListNode *h1 = head, *curr = head->next;
        stack<pair<int,int>> st; int idx = 0, x=0, n = length(h1);
        st.push(make_pair(head->val, idx++));
        vector<int> ans(n,0);
        while(curr) {
            x = curr->val;
            curr = curr->next;
            while(!st.empty() && x > st.top().first) {
                auto t = st.top(); st.pop();
                ans[t.second] = x;
            }
            st.push(make_pair(x, idx++));
        }
        return ans;
    }
};


