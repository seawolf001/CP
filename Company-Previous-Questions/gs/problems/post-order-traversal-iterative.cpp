/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;
typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;
typedef std::vector<string> vs;

class Node {
public:
    int data;
    Node * left;
    Node * right;
    Node(int n) {
        this->data = n;
        this->left = this->right = NULL;
    }
};

void post_order_recurr(Node* node) {
    if (node==NULL) { return; }
    post_order_recurr(node->left);
    post_order_recurr(node->right);
    cout << node->data << " ";
}

void post_order_iter(Node* node) {
    if(node==NULL) return;
    stack<Node*> s1,s2;
    s1.push(node);
    while(!s1.empty()){
        Node* top = s1.top(); s1.pop();
        s2.push(top);
        if(top->left) { s1.push(top->left); }
        if(top->right) { s1.push(top->right); }
    }
    while(!s2.empty()) {
        cout << s2.top()->data << " "; s2.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "Post-order Traversal using recursive methodology : ";
    post_order_recurr(root);
    cout << "\nPost-order Traversal using iterative methodology : ";
    post_order_iter(root);
    cout << endl;
    return 0;
}


