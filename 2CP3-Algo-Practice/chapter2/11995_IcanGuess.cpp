#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int N=0;
int a=0; 
int b=0;

int main(){
	vector<string> v;
	while(cin>>N){
		queue<int> q;
		priority_queue<int> pq;
		stack<int> st;
		bool a1=true, a2=true, a3=true;
		while(N--){
			cin>>a>>b;
			if(a==1){
				if(a1) st.push(b);
				if(a2) q.push(b);
				if(a3) pq.push(b);
			} else {
				if(a1){
					if(st.empty() || st.top()!=b) a1=false;
					else st.pop();
				}
				if(a2){
					if(q.size()==0 || q.front() !=b) a2=false;
					else q.pop();
				}
				if(a3){
					if(pq.size()==0 || pq.top() !=b) a3=false;
					else pq.pop();	
				}
			}
		}
		// cout << a1 <<" " << a2 << " " << a3 << "\n"; 
		if(a1 && !a2 && !a3) /*cout << "stack\n";*/ v.push_back(string("stack"));
		else if(!a1 && a2 && !a3) /*cout << "queue\n";*/ v.push_back(string("queue"));
		else if(!a1 && !a2 && a3) /*cout << "priority queue\n";*/ v.push_back(string("priority queue"));
		else if((a1&a2) || (a1&a3) || (a2&a3)) /*cout << "not sure\n";*/ v.push_back(string("not sure"));
		else /*cout << "impossible\n";*/ v.push_back(string("impossible"));
	}
	for(auto x=v.begin(); x!=v.end(); x++)
		cout << *x << "\n";
	return 0;
}