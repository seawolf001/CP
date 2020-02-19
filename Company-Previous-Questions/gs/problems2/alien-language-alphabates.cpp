/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;
#define CHARS 256

class Graph {
    private:
    unordered_map<int, list<int>> adj;
    public:
    Graph() {
        this->adj.clear();
    }
    void addEdge(int x, int y) {
        this->adj[x].push_front(y);
    }
    void DFS(int v, bool* vis, stack<int> &st) {
        vis[v]=true;
        list<int>::iterator it;
        for(it=this->adj[v].begin(); it!=this->adj[v].end(); it++) {
            if(!vis[*it]){
                DFS(*it, vis, st);
            }
        }
        st.push(v);
    }
    string topologicalSort() {
        stack<int> st;
        while(!st.empty()) { st.pop(); }
        bool * vis = new bool[CHARS];
        memset(vis, false, CHARS * sizeof(bool));
        for(int i=0;i<CHARS; i++) {
            if(!vis[i] && (this->adj).count(i)>0) {
                DFS(i, vis, st);
            }
        }
        string ans = "";
        while(!st.empty()) {
            char c = (char)('a' + st.top());
            ans.push_back(c);
            ans.push_back(' ');
            st.pop();
        }
        delete vis;
        ans.erase(ans.size()-1);
        return ans;
    }
};

string alphabatesOrder(string words[], int n) {
    Graph g;
    for(int i=0;i<n-1;i++) {
        string w1 = words[i];
        string w2 = words[i+1];
        for(int j=0;j<min(w1.length(), w2.length()); j++){
            if(w1[j] != w2[j]){
                g.addEdge(w1[j]-'a', w2[j]-'a');
                break;
            }
        }
    }
    return g.topologicalSort();
}

bool doTestsPass() {
    bool allTestPassing = true;

    string words[] = {"caa", "aaa", "aab"};
    allTestPassing &= alphabatesOrder(words, sizeof(words)/sizeof(words[0])) == "c a b";

    return allTestPassing;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    if(doTestsPass()) {
        cout << "All tests are passing." << endl;
    } else {
        cout << "Did not pass all the test." << endl;
    }
    return 0;
}


