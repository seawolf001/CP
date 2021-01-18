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
        int carry=0, curr=0; ListNode dummy(-1), *node=&dummy;
        while(l1 || l2 || carry)  {
            curr = carry;
            if(l1) curr += l1->val, l1=l1->next;
            if(l2) curr += l2->val, l2=l2->next;
            carry = curr / 10;
            curr = curr % 10;
            node->next= new ListNode(curr);
            node = node->next;
        }
        return dummy.next;
    }
};


