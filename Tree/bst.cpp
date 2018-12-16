#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* insert(struct Node* root, int data){
	if(root == NULL){
		struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
		new_node->data = data;
		new_node->left = NULL;
		new_node->right = NULL;
		return new_node;
	} else if(data < root->data){
		root->left=insert(root->left, data);
	} else if(data > root->data){
		root->right=insert(root->right, data);
	}
	return root;
}
void inorder(Node* root){
	if(root == NULL) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
void pre_order(Node* root){
	if(root == NULL) return;
	cout << root->data << " ";
	pre_order(root->left);
	pre_order(root->right);
}
void post_order(Node* root){
	if(root == NULL) return;
	post_order(root->left);
	post_order(root->right);
	cout << root->data << " ";
}
void level_order(Node* root){
	if(root == NULL) return;
	queue<Node*> q;
	q.push(root);
	while(q.empty() == false){
		Node* new_node = q.front();
		cout << new_node->data << " ";
		q.pop();
		if(new_node->left) q.push(new_node->left);
		if(new_node->right) q.push(new_node->right);
	}  
}
string search(Node* root, int value){
	if(root == NULL) return "";
	if(root->data == value) return "Found";
	if(root->left) return search(root->left, value);
	if(root->right) return search(root->right, value);
	return "Not Found";
} 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	struct Node* root = NULL;
	root = insert(root, 50);
	insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    cout << "Inorder tranversal of tree : ";
    inorder(root);
    cout << "\nPre-Order tranversal of tree : ";
    pre_order(root);
    cout << "\nPost-Order tranversal of tree : ";
    post_order(root);
    cout << "\nLevel-order tranversal of tree : ";
    level_order(root);
    if(search(root, 50).compare("Found")==0) cout << "\nFound";
    if(search(root, 55) == "Not Found") cout << "\nNot Found";
    cout << endl;
	return 0;
}	
