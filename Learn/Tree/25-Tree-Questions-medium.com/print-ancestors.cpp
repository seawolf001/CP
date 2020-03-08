/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Node {
    public:
    int key;
    Node* left, *right;
    Node(int k, Node* l=nullptr, Node* r=nullptr) {
        this->key = k;
        this->left = l;
        this->right = r;
    }
};

bool ancestorsTopToBottom(Node* root, Node* x, list<Node*> &ancestors) {
    if (root == nullptr)
        return false;
    if (root == x)
        return true;
    bool foundInLeft=false, foundInRight=false;
    foundInLeft = ancestorsTopToBottom(root->left, x, ancestors);
    if (!foundInLeft)
        foundInRight = ancestorsTopToBottom(root->right, x, ancestors);
    if(foundInLeft || foundInRight)
        ancestors.push_front(root);
    return foundInLeft || foundInRight;
}

bool doTestsPass() {
    bool allTestsPassing = true;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->right->right = new Node(8);
    list<Node*> expected {root, root->right, root->right->left}, ancestors;
    ancestorsTopToBottom(root, root->right->left->left, ancestors);
    allTestsPassing &= equal(expected.begin(), expected.end(), ancestors.begin());
    delete root;
    /*Start writing from here*/
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


