
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *odd=head, *even=head->next, *even_begin=even;
        while(true) {
            if(even==NULL || even->next==NULL) {
                odd->next = even_begin;
                break;
            }
            odd->next = even->next;
            odd = even->next;
            even->next = odd->next;
            if(odd->next==NULL) {
                odd->next = even_begin;
                break;
            }
            even = odd->next;
        }
        return head;
    }
};
