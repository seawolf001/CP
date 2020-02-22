/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

struct Node {
    int key = 0;
    Node *left, *right;
    Node(int key, Node* left=nullptr, Node* right=nullptr) {
        this->key = key;
        this->left = left;
        this->right = right;
    }
};

vector<int> left_view_iter(Node* root) {
    queue<Node*> q;
    q.push(root);
    Node* front=nullptr;
    int size=0;
    vector<int> order;
    while(!q.empty()) {
        size = q.size();
        int x=1;
        while(size--) {
            front = q.front();
            q.pop();
            if(x==1) {
                order.push_back(front->key);
                x=0;
            }
            if(front->left) {
                q.push(front->left);
            }
            if(front->right) {
                q.push(front->right);
            }
        }
    }
    return order;
}

void preorder(Node* root, int currL, int &prevL, vector<int> &ans) {
    if (root==nullptr) return;
    if(prevL < currL) {
        ans.push_back(root->key);
        prevL = currL;
    }
    preorder(root->left, currL+1, prevL, ans);
    preorder(root->right, currL+1, prevL, ans);
}

vector<int> left_view_recurr(Node* root) {
    vector<int> order;
    int prevL = 0;
    preorder(root, 1, prevL, order);
    return order;
}

bool doTestsPass() {
    bool allTestsPassing = true;
    /*Start writing from here*/
    Node* root=new Node(12);
    root->left=new Node(10);
    root->right=new Node(30);
    root->right->left=new Node(25);
    root->right->right=new Node(40);

    vector<int> expected {12,10,25}, ans;

    ans = left_view_recurr(root);
    allTestsPassing &= equal(expected.begin(), expected.end(), ans.begin());

    ans = left_view_iter(root);
    allTestsPassing &= equal(expected.begin(), expected.end(), ans.begin());

    Node * root1 = new Node(1);
    root1->left = new Node(2);
	root1->right = new Node(3);
	root1->left->right = new Node(4);
	root1->right->left = new Node(5);
	root1->right->right = new Node(6);
	root1->right->left->left = new Node(7);
	root1->right->left->right = new Node(8);

    expected.clear();
    expected.insert(expected.end(), {1,2,4,7});
    ans.clear();

    ans = left_view_recurr(root1);
    allTestsPassing &= equal(expected.begin(), expected.end(), ans.begin());

    ans = left_view_iter(root1);
    allTestsPassing &= equal(expected.begin(), expected.end(), ans.begin());

    delete root, root1;
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


