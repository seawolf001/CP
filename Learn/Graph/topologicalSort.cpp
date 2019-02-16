#include<bits/stdc++.h>
using namespace std;
class Graph{
private:
	int v;
	list<int> *adj;
public:
	Graph(int num){
		this->v=num;
		this->adj = new list<int>[num];
	}
	void add_edge(int u, int v){
		adj[u].push_back(v);
	}
	void topological_util(int v, bool visited[], stack<int> &st){
		visited[v]=true;
		list<int>::iterator it;
		for(it=adj[v].begin(); it!=adj[v].end(); it++){
			if(!visited[*it])
				topological_util(*it, visited, st);
		}
		st.push(v);
	}
	void topological_sort(){
		stack<int> st;
		bool *visited = new bool[v];
		for(int i=0;i<v; i++) visited[i]=false;
		for(int i=0;i<v;i++){
			if(!visited[i]) 
				topological_util(i, visited, st);			
		}
		while(!st.empty()){
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}
};
int main(){
	Graph g(6); 
    g.add_edge(5, 2); 
    g.add_edge(5, 0); 
    g.add_edge(4, 0); 
    g.add_edge(4, 1); 
    g.add_edge(2, 3); 
    g.add_edge(3, 1);
    cout << "Topological sort of given graph is : " << endl;
    g.topological_sort();
    return 0;
}