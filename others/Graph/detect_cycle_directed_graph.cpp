#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
class Graph{
	int num_vertex;
	list<int> *adjacency;
public:
	Graph(int num){
		this->num_vertex = num;
		this->adjacency = new list<int>[num];
	}
	void add_edge(int s, int d){
		this->adjacency[s].push_back(d);
	}
	bool cyclic_util(int v, bool *visited, bool *recursion_stack){
		if(visited[v] == false){
			visited[v] = true;
			recursion_stack[v] = true;
			list<int>::iterator itr;
			for(itr = this->adjacency[v].begin(); itr!= this->adjacency[v].end(); itr++){
				if(visited[*itr] == false && cyclic_util(*itr, visited, recursion_stack)) return true;
				else if(recursion_stack[*itr]) return true;
			}
		}
		recursion_stack[v] = false;
		return false;
	}
	bool contains_cycle_or_not(){
		bool *visited  = new bool[this->num_vertex];
		bool *recursion_stack  = new bool[this->num_vertex];
		memset(visited, false, this->num_vertex);
		memset(visited, false, this->num_vertex);

		for(int i=0; i<this->num_vertex; i++){
			if(cyclic_util(i,visited, recursion_stack)) return true;
		}
		return false;
	}
};
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
    graph.contains_cycle_or_not() ?  cout << "Yes" << "\n" : cout << "No";
	return 0;
}