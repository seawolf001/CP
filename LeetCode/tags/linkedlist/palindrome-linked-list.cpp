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
        ListNode *prev=nullptr, *curr=head, *next=nullptr;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return head = prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *slow=head, *fast=head, *mid=NULL;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast) {
            // number of nodes is odd. ex: 1,2,3,4,5
            mid = slow;
            fast = mid->next;
            slow = head;
        } else {
            // number of nodes is even. ex: 1,2,3,3,2,1
            mid = slow;
            fast = slow;
            slow = head;
        }
        // cout << slow->val << " " << mid->val << " " << fast->val;
        fast = reverse(fast);
        while(slow!=mid) {
            if(slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};


