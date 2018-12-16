#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
class Graph{
private:
	int num_vertex;
	list<int> *adjacency;
	void dfs_util(int v, bool visited[]);
public:
	Graph(int num);
	void add_edge(int v, int w);
	void dfs(int s);
};
Graph::Graph(int num){
	this->num_vertex = num;
	this->adjacency = new list<int>[num];
}
void Graph::add_edge(int v, int w){
	adjacency[v].push_back(w);
}
void Graph::dfs_util(int s, bool visited[]){
	visited[s] = true;
	cout << s << " ";
	for(auto i=adjacency[s].begin(); i!=adjacency[s].end(); i++){
		if(!visited[*i]) {
			dfs_util(*i, visited);
		}
	}
}
void Graph::dfs(int s){
	bool *visited = new bool[num_vertex];
	for(int i=0;i<num_vertex;i++) {
		visited[i]=false;
	}
	dfs_util(s,visited);
	for(int i=0; i< num_vertex; i++){
		if(!visited[i]){
			dfs_util(i, visited);
		}
	}
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Graph graph(5);
	graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(1, 2);
    graph.add_edge(2, 0);
    graph.add_edge(2, 3);
    graph.add_edge(3, 3);
    cout << "DFS starts here:";
    graph.dfs(2);
    cout<<"\n";
	return 0;
}