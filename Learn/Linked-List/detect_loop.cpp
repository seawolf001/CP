#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
void push(struct Node** head, int num){
	struct Node* new_node= (struct Node*)malloc(sizeof (struct Node));
	new_node->data = num;
	new_node->next = (*head);
	(*head) = new_node;
}
bool detect_loop(struct Node** head){
	struct Node* slow_ptr = *head;
	struct Node* fast_ptr = *head;
	while(slow_ptr!=NULL && fast_ptr!=NULL && fast_ptr->next!=NULL){
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		if(slow_ptr == fast_ptr){
			cout<< "Loop found" << endl;
			return true;
		}
	}
	return false;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	struct Node* head = NULL;
	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 10);
	head->next->next->next->next = head;
	if(!detect_loop(&head)){
		cout << "Loop not detected" << '\n';
	}
	return 0;
}