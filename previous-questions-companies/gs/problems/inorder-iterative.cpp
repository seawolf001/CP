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

void inorder_recurr(Node* node) {
    if (node==NULL) { return; }
    inorder_recurr(node->left);
    cout << node->data << " ";
    inorder_recurr(node->right);
}

void inorder_iter(Node* node) {
    if(node==NULL) return;
    stack<Node*> st;
    Node* curr = node;
    while(curr != NULL || st.empty() == false) {
        while(curr != NULL) {
            st.push(curr);
            curr= curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
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
    cout << "Inorder Traversal using recursive methodology : ";
    inorder_recurr(root);
    cout << "\nInorder Traversal using iterative methodology : ";
    inorder_iter(root);
    cout << endl;
    return 0;
}


