/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

struct Node {
    int key;
    Node *left, *right;
    Node(int k, Node* l=nullptr, Node* r=nullptr) {
        this->key = k;
        this->left = l;
        this->right = r;
    }
};

bool isPresent(Node* root, Node* x) {
    if (root == nullptr || x == nullptr) return false;
    return (root == x) || isPresent(root->left, x) || isPresent(root->right, x);
}

Node* LCAUtil(Node* root, Node* x, Node* y) {
    if (root == nullptr || root == x || root == y)
        return root;
    Node* leftLCA = LCAUtil(root->left, x, y);
    Node* rightLCA = LCAUtil(root->right, x, y);
    if (leftLCA && rightLCA)
        return root;
    return leftLCA != nullptr ? leftLCA : rightLCA;
}

Node* LCA(Node* root, Node* x, Node* y) {
    if (root == nullptr)
        return nullptr;
    if(isPresent(root, x) && isPresent(root, y))
        return LCAUtil(root, x, y);
    return nullptr;
}

bool doTestsPass() {
    bool allTestsPassing = true;
    /*Start writing from here*/
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    allTestsPassing &= LCA(root, root->left->left, root->left->right) == root->left;
    allTestsPassing &= LCA(root, root->left->left, root->right->left) == root;
    allTestsPassing &= LCA(root, root->right, root->left->left) == root;
    allTestsPassing &= LCA(root, root->left, root->left->left) == root->left;
    allTestsPassing &= LCA(root, root, new Node(99)) == nullptr;
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


