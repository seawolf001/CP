#include<iostream>
#include<climits>
#include<cstring>
#define fin freopen("in.imp", "r", stdin)
#define fout freopen("out.imp", "w", stdout)
using namespace std;
#define mxn 12
#define mxs 1<<12


int arr[20][20],x[20],y[20];
int N=0,M=0,a=0,b=0,n=0,_min=INT_MAX;
int dp[mxs][mxn];

int TSP(int s, int l){
	if(s==0 && l!=0) return INT_MAX;
	if(dp[s][l]!=-1) return dp[s][l];
	_min = INT_MAX;
	for(int i=0;i<=n;i++){
		if((s & (1<<i))!=0){
			int tmp=TSP(s-(1<<i),i);
			tmp+=arr[i][l];
			_min=min(_min, tmp);
		}
	}
	dp[s][l]=_min;
	return _min;
}

int main(){
	int T=0;
	cin>>T;
	while(T--){
		memset(x,0,sizeof x);
		memset(y,0,sizeof y);
		cin>>N>>M;
		
		cin>>a>>b;
		x[0]=a; 
		y[0]=b;
		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b;
			x[i]=a; y[i]=b;
		}

		for(int i=0;i<=n;i++) {
			for(int j=0;j<=n;j++){
				arr[i][j]=abs(x[i]-x[j])+abs(y[i]+y[j]);
			}
		}
		for(int i=0;i<20;i++){
			for(int j=0;j<20;j++){
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		for(int i=0;i<mxs;i++) for (int j=0;j<mxn;j++) dp[i][j]=-1;
		dp[0][0]=0;
		cout << "The shortest path has length " << TSP((1<<(n+1))-1, 0) << "\n";
	}
	return 0;
}