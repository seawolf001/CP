#include<iostream>
#include<sstream>
#define endl '\n';
#define  N 1000
using namespace std;

int n=0, T=0;
int s=0, f=0;
int parent[N];
int _rank[N];

bool first=false;
char c='\0';
int a=0, b=0;
string str="";

int find(int p){
	if(parent[p]!=p) parent[p]=find(parent[p]);
	return parent[p];
}
void _union(int a, int b){
	int p1=find(a);
	int p2=find(b);
	if(p1==p2) return; 
	if(_rank[p1]>_rank[p2]){
		parent[p2]=p1;
	} else if(_rank[p1]<_rank[p2]){
		parent[p1]=p2;
	} else {
		parent[p1]=p2;
		_rank[p2]++;
	}
}
void _setup(int n){
	s=f=0;
	for(int i=1;i<=n;i++){
		_rank[i]=0;
		parent[i]=i;
	}
}
int main(int argc, char const *argv[])
{
	/*freopen("1in.txt", "r", stdin);
    freopen("1out.txt", "w", stdout);*/
	cin>>T;
	while(T--){
		getchar();
		cin>>n;
		// cout << n;
		s=f=0;
		for(int i=1;i<=N;i++){
			parent[i]=i;
			_rank[i]=0;
		}
		while(true){
			if(cin.eof()) break;
			getline(cin, str);
			if(str.size()==0) break;
			stringstream iss(str);
			iss>>c>>a>>b;
			// cout << c << " " << a << " "<< b << endl;
			if(c=='c') _union(a,b);
			else if(c=='q'){
				if(find(a)==find(b)) s++;
				else f++;
			}
		}
		if(first) cout << "\n";
		first=true;
		cout << s << "," << f << endl;
	}
	return 0;
}
