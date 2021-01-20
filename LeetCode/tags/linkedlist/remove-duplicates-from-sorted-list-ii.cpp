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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *prev = new ListNode(-1, head), *curr=head;
        head=prev;
        while(curr){
           bool flag=false;
           while(curr && curr->next && curr->val==curr->next->val){
               curr = curr->next;
               flag=true;
           }
            if(flag) {
                prev->next=curr->next;
                if(curr->next) curr = curr->next;
            } else {
                prev=curr;
                curr = curr->next;
            }
        }
        return head->next;
    }
};
