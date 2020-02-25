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
    Node(int k, Node* l=nullptr, Node* r=nullptr) {
        this->key = k;
        this->left= l;
        this->right=r;
    }
};

int diameter(Node* root, int& d) {
    if (root==nullptr) return 0;
    int lh = diameter(root->left, d);
    int rh = diameter(root->right, d);
    d = max(lh+rh+1, d);
    return max(rh, lh)+1;
}

int get_diameter(Node* root) {
    int d = 0;
    diameter(root, d);
    return d;
}

bool doTestsPass() {
    bool allTestsPassing = true;
    /*Start writing from here*/
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    allTestsPassing &= get_diameter(root) == 4;

    root = nullptr;

    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    allTestsPassing &= get_diameter(root)==6;

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


