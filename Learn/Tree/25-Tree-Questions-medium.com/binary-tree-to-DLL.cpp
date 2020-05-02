/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

struct Node {
    int x;
    Node* left, *right;
    Node(int d, Node* l=nullptr, Node* r=nullptr) {
        this->x = d;
        this->left = l;
        this->right = r;
    }
};

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

    convert(root);
    int expected[] = {4, 2, 5, 1, 6, 3, 7};
    allTestsPassing &= equal(expected, expected+sizeof(expected)/sizeof(expected[0]), DLL(root))
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


