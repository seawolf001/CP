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
        this->left = this->right = NULL;
    }
};

bool isIdentical(Node* x, Node* y) {
    if(x==NULL && y==NULL) return true;
    else if(x==NULL && y!=NULL) return false;
    else if(x!=NULL && y==NULL) return false;
    return  (x->key==y->key) &&
            (isIdentical(x->left, y->left)) &&
            (isIdentical(x->right, y->right));
}

bool doTestsPass() {
    bool allTestsPassing = true;
    /*Start writing from here*/
    Node* x = new Node(15);
    x->left = new Node(10);
    x->right = new Node(20);
    x->left->left = new Node(8);
    x->left->right = new Node(12);
    x->right->left = new Node(16);
    x->right->right = new Node(25);

    Node* y = x;
    allTestsPassing &= isIdentical(x, y) == true;

    Node* z = new Node(11);
    z->left = x->left;
    z->right = x->right;
    allTestsPassing &= isIdentical(x, z) == false;

    y->left = z->left;
    allTestsPassing &= isIdentical(x, y) == true;

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


