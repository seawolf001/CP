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

void pre_order_recurr(Node* node) {
    if (node==NULL) { return; }
    cout << node->data << " ";
    pre_order_recurr(node->left);
    pre_order_recurr(node->right);
}

void pre_order_iter(Node* node) {
    if(node==NULL) return;
    stack<Node*> st;
    st.push(node);
    while(!st.empty()) {
        Node* top = st.top();
        cout << top->data << " ";
        st.pop();
        if(top->right) { st.push(top->right); }
        if(top->left) { st.push(top->left); }
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
    cout << "Pre-order Traversal using recursive methodology : ";
    pre_order_recurr(root);
    cout << "\nPre-order Traversal using iterative methodology : ";
    pre_order_iter(root);
    cout << endl;
    return 0;
}


