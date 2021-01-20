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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        int length = 0; ListNode *len=head, *tail=NULL, *curr=head;
        while(len) ++length, tail=len, len=len->next;
        k = k % length; int p=1;
        while (p++ < length-k)
            curr = curr->next;
        tail->next = head;
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};


