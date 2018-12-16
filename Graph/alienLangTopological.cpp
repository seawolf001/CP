/*
	Time complexity linear
*/

#include <bits/stdc++.h>
using namespace std;
class Graph{
private:
	int v;
	list<int> *adj;
public:
	Graph(int n){
		this->v=n;
		this->adj = new list<int>[n];
	}
	void add_edge(int a, int b){
		adj[a].push_back(b);
	}
	void util(int v, bool visited[], stack<int> &st){
		visited[v]=true;
		list<int>::iterator it;
		for(it=adj[v].begin(); it!=adj[v].end(); it++){
			if(!visited[*it])
				util(*it, visited, st);
		}
		st.push(v);
	}
	void topological(){
		stack<int>st;
		bool *visited = new bool[v];
		for(int i=0;i<v;i++){
			visited[i]=false;
		}
		for(int i=0;i<v;i++){
			if(!visited[i])
				util(i, visited, st);
		}
		while(!st.empty()){
			cout << (char)('a'+st.top()) << " ";
			st.pop();
		}
		cout << endl;
	}
};
int min(int x, int y){
	return (x<y) ? x:y;
}
void alphabatesOrder(string arr[], int n, int alpha){
	Graph g(alpha);
	for(int i=0;i<n-1;i++){
		string w1=arr[i];
		string w2=arr[i+1];
		for(int j=0;j<min(w1.length(), w2.length()); j++){
			if(w1[j]!=w2[j]){
				g.add_edge(w1[j]-'a', w2[j]-'a');
				break;
			}
		}
	}
	g.topological();
}
int main(){
	string arr[] = {"a", "ac", "acb" };
	int n=sizeof(arr)/sizeof(arr[0]);
	int alpha = 3;
	alphabatesOrder(arr, n, alpha);
	return 0;
}