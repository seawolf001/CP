#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007

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
    typedef pair<ListNode*, int> pli;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0) return NULL;
        auto comparator = [&](const ListNode* x, const ListNode* y) { return x->val > y->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comparator)> minh(comparator);
        for(int i=0;i<k;i++) {
            if(lists[i])  minh.push(lists[i]);
        }
        ListNode *dummy = new ListNode(INT_MIN), *ans=dummy;
        while(!minh.empty()) {
            ListNode* node = minh.top(); minh.pop();
            dummy->next = new ListNode(node->val);
            dummy = dummy->next;
            if(node->next) minh.push(node->next);
        }
        return ans->next;
    }
};


