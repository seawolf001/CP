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
    Node(int key, Node* left=nullptr, Node* right=nullptr) {
        this->key = key;
        this->left = left;
        this->right = right;
    }
};

void bottomView_recurr(Node* root, map<int, int> &mapped, int dist) {
    if(root==nullptr) return;
    mapped[dist] = root->key;
    if (root->left) { bottomView_recurr(root->left, mapped, dist-1); }
    if (root->right) { bottomView_recurr(root->right, mapped, dist+1); }
}

vector<int> bottomView(Node* root) {
    map<int, int> mapped;
    bottomView_recurr(root, mapped, 0);
    vector<int> ans;
    for(auto x: mapped) {
        ans.push_back(x.second);
    }
    return ans;
}

bool doTestsPass() {
    bool allTestsPassing = true;
    /*Start writing from here*/
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    vector<int> expected = {7,5,8,6};
    vector<int> ans = bottomView(root);
    allTestsPassing &= equal(expected.begin(), expected.end(), ans.begin());

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


