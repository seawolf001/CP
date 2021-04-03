/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

struct Node {
    int d;
    Node *left=NULL, *right=NULL;
};

Node* getNode(int d) {
    Node * node = (Node*) malloc(sizeof(Node));
    node->d=d;
    node->left = node->right = NULL;
}

int countPairs(Node* root1, Node* root2, int SUM) {
    if(root1 == NULL || root2 == NULL) return 0;
    stack<Node*> st1, st2;
    Node *top1, *top2;
    int count=0, x=0, y=0;
    while(1) {
        while(root1!=NULL) {
            st1.push(root1);
            root1 = root1->left;
        }
        while(root2!=NULL) {
            st2.push(root2);
            root2 = root2->right;
        }
        if(st1.empty() || st2.empty())
            break;

        top1 = st1.top();
        x = top1->d;

        top2 = st2.top();
        y = top2->d;

        if(x+y == SUM) {
            count++;
            st1.pop();
            st2.pop();
            root1 = top1->right;
            root2 = top2->left;
        } else if(x+y<SUM) {
            st1.pop();
            root1 = top1->right;
        } else {
            st2.pop();
            root2 = top2->left;
        }
    }
    return count;
}

bool doTestsPass() {
    bool allTestsPassing = true;
    /*Start writing from here*/

    Node* root1 = getNode(5); /*		  5	 */
	root1->left = getNode(3); /*		 / \	 */
	root1->right = getNode(7); /*		 3	 7	 */
	root1->left->left = getNode(2); /* / \ / \ */
	root1->left->right = getNode(4); /* 2 4 6 8 */
	root1->right->left = getNode(6);
	root1->right->right = getNode(8);

	// formation of BST 2
	Node* root2 = getNode(10); /*		 10		 */
	root2->left = getNode(6); /*		 / \	 */
	root2->right = getNode(15); /*	    6	 15	 */
	root2->left->left = getNode(3); /* / \ / \	 */
	root2->left->right = getNode(8); /* 3 8 11 18 */
	root2->right->left = getNode(11);
	root2->right->right = getNode(18);

    allTestsPassing &= countPairs(root1, root2, 16)==3;

    return allTestsPassing;
}

int main() {
    ios_base::sync_with_stdio(false);
    if(doTestsPass()) {
        cout << "\nAll Tests Passed.\n" << endl;
    } else {
        cout << "\nFailed for one or more tests.\n" << endl;
    }
    return 0;
}


