#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1, s2;
        while(l1) s1.push(l1), l1=l1->next;
        while(l2) s2.push(l2), l2=l2->next;
        int carry=0, sum=0; ListNode* head=NULL;
        while(!s1.empty() || !s2.empty() || carry) {
            sum = carry;
            if(!s1.empty()) sum += s1.top()->val, s1.pop();
            if(!s2.empty()) sum += s2.top()->val, s2.pop();
            ListNode* newnode = new ListNode(sum%10, head);
            head = newnode;
            carry = sum/10;
        }
        return head;
    }
};


