#include<bits/stdc++.h>
using namespace std;

struct node {
    struct node *left, *right;
    int data;
};

struct node* newNode(int data){
    struct node* temp=new node;
    temp->left=temp->right=NULL;
    temp->data=data;
    return temp;
}

int height(struct node* root){
    if(root==NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh+1, rh+1);
}

void printLeftToRight(struct node* root, int level){
    if (root==NULL) return;
    if(level==1) {
        cout << root->data << " ";
    } else if(level>1){
        printLeftToRight(root->left, level-1);
        printLeftToRight(root->right, level-1);
    }
}

void printRightToLeft(struct node* root, int level){
    if(root==NULL) return;
    if (level==1){
        cout << root->data << " ";
    } else if(level>1){
        printRightToLeft(root->right, level-1);
        printRightToLeft(root->left, level-1);
    }
}

void printZigZag(struct node* root){
    int flag=0;
    int h=height(root);
    for(int i=1;i<=h;i++){
        if(flag==1){
            printRightToLeft(root, i);
            flag=0;
        } else if(flag==0){
            printLeftToRight(root, i);
            flag=1;
        }
    }
}

int main(){
    struct node* root=newNode(7);
    root->left = newNode(4);
    root->right = newNode(5);
    root->left->left = newNode(9);
    root->right->right = newNode(10);
    root->left->left->left = newNode(6);
    root->left->left->right = newNode(11);

    printZigZag(root);
    return 0;
}
