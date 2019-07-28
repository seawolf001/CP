#include<bits/stdc++.h>
using namespace std;

class Graph {
    int v;
    list<int>*  adj;
public:
    Graph(int v){
        this->v = v;
        adj = new list<int>[v];
    }
    void addEdge(int x, int y){
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    void DFS(int v, bool visited[]){
        visited[v]=true;
        list<int>::iterator itr;
        for(itr=adj[v].begin(); itr!=adj[v].end(); itr++){
            if(!visited[*itr]) {
                DFS(*itr, visited);
            }
        }
    }
    int numberOfConnectedComponents() {
        bool* visited = new bool[v];
        for (int x=0;x<v;x++) {
            visited[x]=false;
        }
        int count=0;
        for(int i=0;i<v;i++){
            if(visited[i]==false){
                DFS(i, visited);
                count++;
            }
        }
        return count;
    }
};

int main(){
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    cout << "Total number of connected components in the given graph are: " << g.numberOfConnectedComponents() << endl;
    return 0;
}
