/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

struct Node {
    int key;
    Node* left, *right;
    Node(int key) {
        this->key=key;
        this->left = this->right= NULL;
    }
};

int height(Node* root) {
    if (root==NULL) return 0;
    return (1+max(height(root->left), height(root->right)));
}

bool doTestsPass() {
    bool allTestsPassing = true;
    /*Start writing from here*/
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);

    allTestsPassing &= height(root)==3;

    root->left->left->left = root->right;
    allTestsPassing &= height(root)==5;

    root->left->left->left = NULL;
    allTestsPassing &= height(root)==3;

    return allTestsPassing;
}

int main() {
    ios_base::sync_with_stdio(false);
    if(doTestsPass()) {
        cout << "\nAll Tests Passed.\n" << endl;
    } else {
        cout << "\nFailed for one or more tests.\n" << endl;
    }
    return 0;
}


