#include<iostream>
#include<vector>
#define endl "\n"
using namespace std;


int n=0, m=0, k=0, v=0, t=0;
vector<vector<int>> adj;

int main(){
	/*freopen("1in.txt", "r", stdin);
    freopen("1out.txt", "w", stdout);*/
	while(cin>>n>>m){
		adj.assign(1000001, vector<int>());
		for(int i=0;i<n;i++){
			cin>>t;
			adj[t].push_back(i+1);
		}
		/*for(int i=0;i<n;i++){
			for(int j=0;j<(adj[i].size());j++){
				cout << adj[i][j].first << " " << adj[i][j].second << " ";
			}
			cout << endl;
		}*/
		while(m--){
			cin>>k>>v;
			k--;
			if(k<adj[v].size()) cout << adj[v][k] << endl;
			else cout << "0\n";
		}
	}
	return 0;
}