#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
class Graph{
	int num_vertex;
	list<int> *adjacency;
public:
	Graph(int num);
	void add_edge(int v, int w);
	void bfs(int s);
};
Graph::Graph(int num){
	this->num_vertex = num;
	this->adjacency = new list<int>[num];
}
void Graph::add_edge(int v, int w){
	adjacency[v].push_back(w);
}
void Graph::bfs(int s){
	bool *visited = new bool[num_vertex];
	for(int i=0;i<num_vertex;i++) {
		visited[i]=false;
	}
	queue <int> queue;
	visited[s]=true;
	queue.push(s);
	while(!queue.empty()){
		s = queue.front();
		cout << s << " ";
		queue.pop();
		for(auto i = adjacency[s].begin(); i!= adjacency[s].end(); i++){
			if(!visited[*i]){
				visited[*i] = true;
				queue.push(*i);
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Graph graph(4);
	graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(1, 2);
    graph.add_edge(2, 0);
    graph.add_edge(2, 3);
    graph.add_edge(3, 3);
    cout << "BFS starts here:";
    graph.bfs(2);
    cout<<"\n";
	return 0;
}