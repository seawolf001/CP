#include<bits/stdc++.h>
using namespace std;

struct node{
    int n; 
    node* left;
    node* right;
};
node* newnode(int x){
    node* _node = (node *)(malloc(sizeof (node)));
    _node->n=x;
    _node->left = _node->right = NULL;
    return _node;
}

node* insert(int x, node* root){
    // if(root) cout << "x="<<x<<" node->n=" << root->n << "\n";
    if(root == NULL){
        return newnode(x);
    } else if(x <= root->n){
        root->left = insert(x, root->left);
    } else {
        root->right = insert(x, root->right);
    }
    return root;
}

int height(node* root){
    if(root==NULL) return 0;
    return max(height(root->left), height(root->right))+1;
}

int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    int ld = diameter(root->left);
    int rd = diameter(root->right);
    
    // cout << "lh="<<lh<<" rh="<<rh<<" ld="<<ld<<" rh="<<rh<<endl;
    return max(lh+rh+1, max(ld, rd));
}

int main(){
    int n=0; cin>>n;
    node* root=NULL;
    while(n--){
        int x=0; cin>>x;
        root = insert(x, root);
        // cout << "root->n="<<root->n << "\n";
    }
    cout <<diameter(root) << "\n";
    return 0;
}