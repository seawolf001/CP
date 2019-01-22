#include<iostream>
#include<cstring>
#include<string>
#include<vector>

#define n 26
#define m 26
using namespace std;

int N=0;
bool p[26];
bool v[26];
int g[n][m];
bool loop=false;

void dfs(int s, int prev, int &c){
	v[s]=true;
	c++;
/*	cout << "curr="<<(char)('A'+s)<<" prev="<<(char)('A'+prev)<<"\n";*/
	for(int i=0;i<m;i++){
		if(g[s][i] && p[i] && !v[i]) 
			dfs(i,s,c);
		else if(g[s][i] && p[i] && v[i] && i!=prev){
			loop=true;
		}			
	}
}

int main(){
	cin>>N;
	while(N--){
		memset(p, false, sizeof(p));
		memset(v, false, sizeof(v));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				g[i][j]=0;
		string s;
		while(cin>>s, s[0]!='*'){
			g[s[1]-'A'][s[3]-'A']=1;
			g[s[3]-'A'][s[1]-'A']=1;
		}
		cin>>s;
		for(int i=0;i<s.size();i+=2){
			p[s[i]-'A']=true;
		}
		int tree=0; int acorn=0;
		for(int i=0;i<sizeof(v);i++){
			if(!v[i] && p[i]){
				int c=0; loop=false;
				dfs(i,-1,c);
				if(!loop && c>1) tree++;
				else if(c==1) acorn++;
			}
		}
		cout << "There are " << tree << " tree(s) and "<< acorn << " acorn(s).\n";
	}
	return 0;
}