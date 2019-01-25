#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#define endl "\n"
using namespace std;

int n=0,m=0;
vector<vector<pair<int, int>>> adj;
vector<vector<pair<int, int>>> tadj;
int pos[1005];
int num[1005];
int nn=0, t=0;

int main(){
	while(cin>>n){
		if(n==EOF) break;
		cin>>m;
		adj.assign(n, vector<pair<int, int>>());
		adj.assign(m, vector<pair<int, int>>());
		memset(pos, 0, sizeof pos);
		memset(num, 0, sizeof num);
		for(int i=0;i<n;i++){
			cin>>nn;
			cout << nn << endl;
			if(nn==0) {
				// cin.ignore();
				cin>>t;
			} else {
				for(int j=0;j<nn;j++){
					cin>>t;
					pos[j]=t-1;
					cout << t << " ";
				}
				for(int j=0;j<nn;j++){
					cin>>t;
					num[j]=t;
					cout << t << " ";
				}
				for(int j=0;j<nn;j++){
					adj[i].push_back(make_pair(pos[j], num[j]));
				}
			}
			cout << endl;
		}
		for(int i=0;i<nn;i++){
			for(int j=0;j<adj[i].size();j++){
				auto tmp = adj[i][j];
				tadj[tmp.first].push_back(make_pair(i, tmp.second));
			}
		}
		cout << m << " " << n << "\n";
		for(int i=0; i<m ;i++){
			cout << tadj[i].size() << " ";
			for(int j=0;j<tadj[i].size();j++){
				cout << " " << tadj[i][j].first+1;
			}
			cout << endl;
			for(int j=0;j<tadj[i].size();j++){
				cout << tadj[i][j].second;
				if(j<tadj[i].size()-1) cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}