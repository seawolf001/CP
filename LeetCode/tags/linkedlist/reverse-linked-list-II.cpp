
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m>=n || !head || !head->next) return head;
        ListNode *prev=head,
                *next=NULL,
                *curr=head,
                *mth=NULL,
                *nth=NULL,
                *mprev=NULL,
                *nnext=NULL;
        int x=1;
        while(curr) {
            next = curr->next;
            if(x==m) {
                mprev = prev;
                mth = curr;

            }
            if(x>m && x<=n) {
                curr->next = prev;
            }
            if(x==n) {
                nnext = next;
                nth = curr;
            }
            prev = curr;
            curr = next;
            if(x==n) break;
            x++;
        }
        mprev->next = nth;
        mth->next = nnext;
        if(m==1) head=nth;
        return head;
    }
};


