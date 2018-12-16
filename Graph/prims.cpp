#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int u,v,w;
}
class Graph{
private:
	int v;
	list<Edge> *adj;
public:
	Graph(int n){
		this->v=n;
		this->adj = new list<Edge>[n];
	}
	void add_edge(int a, int b, int w){
		pair<int,int> p = make_pair(b,w);
		adj[a].push_back(p);
	}
};
int main(){
	Graph g(5);
	g.add_edge();
	g.add_edge();
	g.add_edge();
	g.add_edge();
	g.add_edge();
	g.add_edge();
	g.add_edge();
	g.add_edge();
	g.add_edge();
	g.add_edge();
	g.add_edge();
	g.add_edge();
	g.add_edge();
	return 0;
}