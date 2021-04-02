#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* merge2lists(ListNode* l1, ListNode* l2) {
    if(l1==l2) return l1;
    else if(l1==NULL) return l2;
    else if(l2==NULL) return l1;
    ListNode *dummy=new ListNode(INT_MIN), *tail=dummy;
    while(l1 && l2) {
        if(l1->val < l2->val) tail->next=l1, l1=l1->next;
        else tail->next=l2, l2=l2->next;
        tail=tail->next;
    }
    tail->next = l1 != NULL ? l1 : l2;
    return dummy->next;
}

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    if(n==0) return NULL;
    int last = n-1, l,r;
    while(last!=0) {
        l = 0, r = last;
        while(l<r) {
            A[l] = merge2lists(A[l], A[r]);
            ++l, --r;
        }
        if(l>=r) last = r;
    }
    return A[0];
}


