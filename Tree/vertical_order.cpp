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
map<int, vector<int>> get_vertical_order(Node* root, int horizontal_dist, map<int, vector<int>> map){
	if(root == NULL) return map;
	map[horizontal_dist].push_back(root->data);
	map = get_vertical_order(root->left, horizontal_dist-1, map);
	map = get_vertical_order(root->right, horizontal_dist+1, map);
	return map;
}
void inorder(Node* root){
	if(root == NULL) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
int main(){
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
    /*
						50
			30						70
	20			   40		60 				80

    */
    cout << "Inorder tranversal of tree : ";
    inorder(root);
    cout << "\nVertical Order : \n";
    /*Vertical order*/
    map<int, vector<int>> map;
    int horizontal_dist = 0;
    map = get_vertical_order(root, horizontal_dist, map);
    for(auto iterator=map.begin(); iterator != map.end(); iterator++){
    	for(int i=0; i < iterator->second.size(); i++){
    		cout<< iterator->second[i] << " ";
    	}
    	cout << '\n';
    }
	return 0;
}