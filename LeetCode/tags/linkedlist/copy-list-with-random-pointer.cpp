#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node *curr = head, *copy=NULL, *copyh=NULL;
        while(curr) {
            copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next=copy;
            curr = copy->next;
        }
        curr = head;
        while(curr && curr->next) {
            curr->next->random = curr->random ? curr->random->next : NULL;
            curr = curr->next->next;
        }
        curr = head, copy=curr->next, copyh=copy;
        while(copy) {
            curr->next = curr->next ? curr->next->next : NULL;
            copy->next = copy->next ? copy->next->next : NULL;
            copy = copy->next;
            curr = curr->next;
        }
        return copyh;
    }
};


