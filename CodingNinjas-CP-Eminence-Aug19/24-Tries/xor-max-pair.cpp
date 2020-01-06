/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;
#define BITS 32

class TrieNode {
    public:
        TrieNode* left;
        TrieNode* right;
};

void insert(int n, TrieNode* head) {
    TrieNode * curr = head;
    for(int i=31; i>=0; i--) {
        int b = (n>>i) & 1;
        if(b == 0) {
            if(!curr->left) {
                curr->left = new TrieNode();
            }
            curr = curr->left;
        } else {
            if(!curr->right) {
                curr->right = new TrieNode();
            }
            curr= curr->right;
        }
    }
}

int findMaxXorPair(TrieNode* head, int* arr, int n) {
    int max_xor = INT_MIN;
    for (int i=0;i<n;i++) {
        TrieNode * curr = head;
        int curr_xor = 0;
        int v = arr[i];
        for(int j=31;j>=0; j--) {
            int b = (v>>j)&1;
            if(b == 0) {
                if (curr->right) {
                    curr_xor += pow(2, j);
                    curr = curr->right;
                } else {
                    curr = curr->left;
                }
            } else {
                if(curr->left) {
                    curr_xor += pow(2, j);
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            }
        }
        max_xor = max(max_xor, curr_xor);
    }
    return max_xor;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int arr[6] = {8,2,15,10,5};
    TrieNode* head = new TrieNode();
    for(int i=0;i<6;i++) { insert(arr[i], head); }
    cout << findMaxXorPair(head, arr, 6) << "\n";
    return 0;
}


