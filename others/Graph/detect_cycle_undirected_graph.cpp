#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class Graph{
private:
	int vertex;
	list<int>* adj;
public:
	Graph(int num){
		this->vertex = num;
		this->adj = new list<int>[num];
	}
	void add_edge(int a, int b){
		this->adj[a].push_back(b);
	}
	bool util(int v, bool *visited, int parent){
		visited[v] = true;
		list<int>::iterator itr;
		for(itr = this->adj[v].begin(); itr!=adj[v].end(); itr++){
			if(!visited[*itr]){
				if(util(*itr, visited, v)) return true;
			}
			else if(*itr != parent) return true;
		}
		return false;
	}
	bool contains_cycle_or_not(){
		bool *visited  = new bool[this->vertex];
		memset(visited, false, this->vertex);
		for(int i=0; i<this->vertex; i++){
			if(!visited[i]){
				if(util(i, visited, -1)) return true;
			}
		}
		return false;
	}
};
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Graph g1(5);
    g1.add_edge(1, 0);
    g1.add_edge(0, 2);
    g1.add_edge(2, 0);
    g1.add_edge(0, 3);
    g1.add_edge(3, 4);

    g1.contains_cycle_or_not() ? cout << "Yes" << endl :
    								cout << "No" << endl;

    Graph g2(4);
    g2.add_edge(0, 1);
    g2.add_edge(1, 2);
    g2.contains_cycle_or_not() ? cout << "Yes" << endl :
    								cout << "No" << endl;
	return 0;
}