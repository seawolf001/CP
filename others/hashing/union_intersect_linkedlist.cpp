#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef std::vector<ll> vll;
typedef std::vector<ld> vld;
typedef std::vector<int> vi;
typedef std::vector<string> vs;
const ll mod=1e9+7;
#define fastscan ios_base::sync_with_stdio(false); cin.tie(NULL);
#define Ignore cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define F1(i,a,b) for(int i=a;i<b;i++)
#define F2(i,a,b) for(int i=a;i<=b;i++)
#define F3(i,a,b) for(int i=a;i>b;i--)
#define F4(i,a,b) for(int i=a;i>=b;i--)
#define For(it,m) for(auto it=(m).begin(); it!=(m).end(); it++)
#define endl '\n'
#define mp make_pair
#define pb(x) push_back((x))
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b);}

vs split(string s, char delimiter){
	vs tokens;
	string token;
	stringstream token_stream(s);
	while(getline(token_stream, token, delimiter)){
		tokens.pb(token);
	}
	return tokens;
}
/********************************************************************************/
struct Node{
	int data;
	struct Node* next;
};
void push(struct Node** head, int num){
	struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
	newnode->data=num;
	newnode->next=(*head);
	*head=newnode;
}
void hash_elements(struct Node* h1, struct Node* h2, unordered_map<int, int> &hash){
	struct Node* p1=h1; struct Node* p2=h2;
	while(p1!=NULL || p2!=NULL){
		if(p1!=NULL){
			hash[p1->data]++;
			p1=p1->next;
		}
		if(p2!=NULL){
			hash[p2->data]++;
			p2=p2->next;
		}
	}
}
int main(int argc, char const *argv[])
{
	fastscan
	/*Start writing from here*/
	struct Node* head1=NULL; struct Node* head2=NULL;
	push(&head1, 1); 
    push(&head1, 2); 
    push(&head1, 3); 
    push(&head1, 4); 
    push(&head1, 5); 

    push(&head2, 1); 
    push(&head2, 3); 
    push(&head2, 5); 
    push(&head2, 6);

    cout<<"First Linked-List : ";
    struct Node* temp=head1;
    while(temp!=NULL){
    	cout << temp->data << " ";
    	temp=temp->next;
    }

    cout <<"\nSecond Linked-List : ";
    temp=head2;
    while(temp!=NULL){
    	cout << temp->data << " ";
    	temp=temp->next;
    }
    unordered_map<int,int>hash;
    hash_elements(head1, head2, hash);

    cout << "\nUnion [elements] of two Linked-List : ";
    For(it,hash) cout << it->first << " ";

    cout << "\nIntersection [elements] of two Linked-List : ";
    For(it,hash) if(it->second==2) cout<< it->first << " ";

    cout << endl;
	return 0;
}