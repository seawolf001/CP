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
        this->left = l;
        this->right = r;
    }
};

vector<int> inorder(Node* root, vector<int> arr={}) {
    if(root == nullptr) return arr;
    arr = inorder(root->left, arr);
    arr.push_back(root->key);
    arr = inorder(root->right, arr);
    return arr;
}

vector<int> preorder(Node* root, vector<int> arr={}) {
    if(root==nullptr) return arr;
    arr.push_back(root->key);
    arr = preorder(root->left, arr);
    arr = preorder(root->right, arr);
    return arr;
}

bool IsSubArray(vector<int>x, vector<int>y) {
    vector<int>::iterator it1 = x.begin(), it2 = y.begin();
    bool ans=true;
    bool matching=false;
    while(it1 != x.end()) {
        if(*it1 == *it2) {
            if(!matching)
                matching=true;
            it2++;
        } else if(matching) {
            it2 = y.begin();
        }
        it1++;
    }
    return it2 == y.end();
}

bool IsSubtree(Node* root1, Node* root2) {
    if (root2==nullptr)
        return true;
    if (root1==nullptr)
        return false;

    bool ans=true;

    vector<int> in1 = inorder(root1);
    vector<int> in2 = inorder(root2);
    ans &= IsSubArray(in1, in2);

    vector<int> pre1 = preorder(root1);
    vector<int> pre2 = preorder(root2);
    ans &= IsSubArray(pre1, pre2);

    return ans;
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

    allTestsPassing &= IsSubtree(root, root->right);

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


