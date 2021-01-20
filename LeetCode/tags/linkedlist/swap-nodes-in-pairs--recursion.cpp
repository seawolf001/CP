
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *curr=head->next, *prev=head, *next=NULL;
        head=curr;
        prev->next = swapPairs(curr->next);
        curr->next = prev;

        // int x=0;
        // while(curr) {
        //     next = curr->next;
        //     prev->next = curr->next;
        //     curr->next = prev;
        //     // if(x==0) head=curr, x=1;
        //     prev = next;
        //     curr = prev ? prev->next : NULL;
        // }
        return head;
    }
};


