/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x <<" is " << (x) << endl;

struct Node {
    int key;
    struct Node* left, *right;
    Node(int data, Node* left=nullptr, Node* right=nullptr) {
        this->key = data;
        this->left = left;
        this->right = right;
    }
};

void insert(Node* root, int data) {
    Node* node = new Node(data);
    Node* x=root;
    Node* y=nullptr;
    while(x!=nullptr) {
        y = x;
        if(data < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    if (y==nullptr) {
        y = node;
    } else if(data < y->key){
        y->left = node;
    } else {
        y->right = node;
    }
}

void postorder_recurrsive(Node* root, vector<int> &order) {
    if (root==nullptr) return;
    postorder_recurrsive(root->left, order);
    postorder_recurrsive(root->right, order);
    order.push_back(root->key);
}

vector<int> postorder_recurr(Node* root) {
    vector<int> order;
    postorder_recurrsive(root, order);
    return order;
}

vector<int> postorder_iter(Node* root) {
    vector<int> order;
    if(root==nullptr) return order;
    stack<Node*> stack;
    while(true) {
        throw string("NotImplemtentedError");
    }
    return order;
}

bool doTestsPass() {
    bool allTestsPassing = true;
    /*Start writing from here*/
    /*
     *                  50
     *          30              70
     *      20      40      60      80
     *
     */
    Node* root = new Node(50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    vector<int> expected {20, 40, 30, 60, 80, 70, 50};

    vector<int> ans = postorder_recurr(root);
    allTestsPassing &= equal(expected.begin(), expected.end(), ans.begin());
    try {
        ans=postorder_iter(root);
        allTestsPassing &= equal(expected.begin(), expected.end(), ans.begin());
    } catch(string error) {
        allTestsPassing = false;
        cout << error << endl;
    }

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


