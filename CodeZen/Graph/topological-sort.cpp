/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;
typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;
typedef std::vector<string> vs;

void topologicalSortUtil(Graph g, int v, bool * visited, stack<int> &Stack) {
    visited[v] = true;
    list<int>::iterator it;
    for (it=g.adj[v].begin(); it!=g.adj[v].end(); it++) {
        if(visited[*it] == false) {
            topologicalSortUtil(g, *it, visited, Stack);
        }
    }
    Stack.push(v);
}

void topologicalSort(Graph g){
    int n = g.V;
    bool * visited = new bool[n];
    for (int i=0;i<n;i++) visited[i] = false;

    stack<int> Stack;
    for (int i=0;i<n;i++) {
        if (visited[i] == false) {
            topologicalSortUtil(g, i,visited, Stack);
        }
    }
    while(Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << "\n";
}

