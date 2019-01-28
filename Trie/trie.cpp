#include <bits/stdc++.h>
using namespace std;
#define N 26

struct Node{
	struct Node *children[N];
	bool end;
};

struct Node *newnode(){
	struct Node *newnode = new Node;
	newnode->end=false;
	for(int i=0;i<N;i++){
		newnode->children[i]=NULL;
	}
	return newnode;
}

void insert(struct Node *root, string key){
	struct Node *curr = root;
	for(int i=0;i<key.length();i++){
		int j=key[i]-'a';
		if(!(curr->children[j])){
			curr->children[j]=newnode();
		}
		curr = curr->children[j];
	}
	curr->end=true;

}

bool search(struct Node *root, string key){
	struct Node *curr=root;
	for(int i=0;i<key.length();i++){
		int j=key[i]-'a';
		if(!(curr->children[j])) return false;
		curr=curr->children[j];
	}
	return (curr!=NULL && curr->end);
}

void printTrie(struct Node *root, string s, int level){
	if(root->end){
		s[level]='\0';
		cout << s << "\n";
	}
	for(int i=0;i<N;i++){
		if(root->children[i]){
			s[level]= i+'a';
			printTrie(root->children[i], s, level+1);
		}
	}
}

int main(){
	string keys[]={"the", "a", "there", "answer", "any", "by", "bye", "their" }; 
	int n=sizeof(keys)/sizeof(keys[0]);
	
	struct Node *root= newnode();
	for(int i=0;i<n;i++) 
		insert(root, keys[i]);

	search(root, "the") ? cout << "Yes\n" : cout << "No\n";
	search(root, "these") ? cout << "Yes\n" : cout << "No\n";

	printTrie(root, string(""), 0);
	return 0;
}	