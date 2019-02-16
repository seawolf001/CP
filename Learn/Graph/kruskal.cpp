#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int src;
	int dest;
	int w;
};
struct Graph{
	int V,E;
	struct Edge* edge;
};
struct subset{
	int parent;
	int rank;
};
struct Graph* createGraph(int v, int e){
	struct Graph* g = new Graph;
	g->V=v;
	g->E=e;
	g->edge = new Edge[e];
	return g;
};
int find(struct subset subsets[], int i){
	if(subsets[i].parent!=i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}
void Unian(struct subset subsets[], int x, int y){
	int xr = find(subsets, x);
	int yr = find(subsets, y);
	if(subsets[xr].rank < subsets[yr].rank){
		subsets[xr].parent = yr;
	} else if(subsets[xr].rank > subsets[yr].rank){
		subsets[yr].parent=xr;
	} else{
		subsets[yr].parent=xr;
		subsets[xr].rank++;
	}
}
int comp(Edge a, Edge b){
	return a.w < b.w;
}
void Krushkal(Graph* g){
	int v=g->V;
	struct Edge result[v];
	int e=0;
	sort(g->edge, g->edge + g->E, comp);
	for(int i=0;i<g->E;i++){
		cout << g->edge[i].src << " " << g->edge[i].dest << " " << g->edge[i].w << "\n";
	}
	cout << "\n" ;
	struct subset* subsets = (struct subset*) malloc(v*sizeof(struct subset));
	for(int i=0;i<v;i++){
		subsets[i].parent=i;
		subsets[i].rank=0;
	}
	int i=0;
	e=0;
	while(e<v-1){
		struct Edge _next = g->edge[i++];
		int x=find(subsets, _next.src);
		int y=find(subsets, _next.dest);
		if(x!=y){
			result[e++]=_next;
			Unian(subsets, x, y);
		}
	}
	cout << "Minimum Spanning Tree using Krushkal's Algorithm \n";
	for(int i=0;i<e;i++){
		cout << result[i].src << " " << result[i].dest << " " << result[i].w << "\n";
	}
}
int main(){
	int V=4, E=5;
	struct Graph* graph=createGraph(V,E);
	// add Edge 0-1
	graph->edge[0].src = 0; 
    graph->edge[0].dest = 1; 
    graph->edge[0].w = 10; 
  
    // add Edge 0-2 
    graph->edge[1].src = 0; 
    graph->edge[1].dest = 2; 
    graph->edge[1].w = 6; 
  
    // add Edge 0-3 
    graph->edge[2].src = 0; 
    graph->edge[2].dest = 3; 
    graph->edge[2].w = 5; 
  
    // add Edge 1-3 
    graph->edge[3].src = 1; 
    graph->edge[3].dest = 3; 
    graph->edge[3].w = 15; 
  
    // add Edge 2-3 
    graph->edge[4].src = 2; 
    graph->edge[4].dest = 3; 
    graph->edge[4].w = 4;

    Krushkal(graph);
	return 0;
}