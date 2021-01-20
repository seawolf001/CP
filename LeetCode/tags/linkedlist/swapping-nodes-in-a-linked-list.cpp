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
    int nodesCount(ListNode* head) {
        int count=0;
        while(head) head=head->next, ++count;
        return count;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head) return head;
        ListNode *len=head, *k1=head, *k2=head;
        int length = nodesCount(len), kl=length-k+1;
        while(--k) k1=k1->next;
        while(--kl) k2=k2->next;
        int tmp = k1->val;
        k1->val = k2->val;
        k2->val=tmp;
        return head;
    }
};
