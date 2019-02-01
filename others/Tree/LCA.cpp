#include <bits/stdc++.h>
using namespace std;

struct Node {
	struct Node *left, *right;
	int data;
};
struct Node* newNode(int data){
	struct Node* new_data = (struct Node*)malloc(sizeof(struct Node));
	new_data->data = data;
	new_data->left = NULL;
	new_data->right = NULL;
	return new_data; 
}
struct Node* util(struct Node* root, int a, bool &v1, int b, bool &v2){
	if(root==NULL)
		return NULL;
	if(root->data == a){
		v1=true;
		return root;
	}
	if(root->data == b){
		v2=true;
		return root;
	}
	struct Node* leftLCA = util(root->left, a, v1, b, v2);
	struct Node* rightLCA = util(root->right, a, v1, b, v2);
	if(leftLCA && rightLCA){
		return root;
	}
	return (leftLCA != NULL) ? leftLCA : rightLCA;
}
bool find(struct Node*  root, int n){
	if(root==NULL) return false;
	if((root->data == n) || find(root->left, n) || find(root->right, n))
		return true;
	return false;
}
struct Node* findLCA(struct Node* root, int a, int b){
	bool v1=false,v2=false;
	struct Node* lca = util(root, a, v1, b, v2);
	if(v1 && v2 || v1 && find(lca, b) || v2 && find(lca, a))
		return lca;
	return NULL;
}
int main() 
{ 
    // Let us create binary tree given in the above example 
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    struct Node* lca =  findLCA(root, 4, 5);
    if (lca != NULL) 
       cout << "LCA(4, 5) = " << lca->data << endl; 
    else
       cout << "datas are not present\n"; 
  
    lca =  findLCA(root, 4, 10); 
    if (lca != NULL) 
       cout << "LCA(4, 10) = " << lca->data << endl; 
    else
       cout << "datas are not present\n"; 
    return 0; 
}