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
private:
    ListNode* reverse(ListNode* head) {
        ListNode *curr=head, *next=NULL, *prev=NULL;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!(l1 && l2)) return NULL;
        else if(l1==NULL) return l2;
        else if(l2==NULL) return l1;
        l1 = reverse(l1), l2 = reverse(l2);
        int carry=0, sum=0; ListNode *dummy = new ListNode(-1), *curr=dummy;
        while(l1||l2||carry) {
            sum = carry;
            if(l1) sum += l1->val, l1=l1->next;
            if(l2) sum += l2->val, l2=l2->next;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            carry = sum/10;
        }
        return reverse(dummy->next);
    }
};


