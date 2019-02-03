#include<iostream>
#include<cstring>
#define fileIn freopen("in.imp", "r", stdin)
#define fileOut freopen("out.imp", "w", stdout)
using namespace std;

int T=0,n=0,a=0,b=0,g=0,W=0;

int knapsack(int W, int wt[], int p[], int n){
	int dp[n+1][W+1];
	for(int i=0;i<=n;i++){
		for(int w=0;w<=W;w++){
			if(i==0||w==0) dp[i][w]=0;
			else if(wt[i-1]>w){
				/* case not in search space */
				dp[i][w]=dp[i-1][w];
			} else if(wt[i-1]<=w){
				dp[i][w]=max(dp[i-1][w], dp[i-1][w-wt[i-1]]+p[i-1]);
			}
		}
	}
	return dp[n][W];
}

int main(){
	/*fileIn;
	fileOut;*/
	cin>>T;
	while(T--){
		cin>>n;
		int p[n];
		int w[n];
		memset(p,0,sizeof p);
		memset(w,0,sizeof w);
		for(int i=0;i<n;i++){
			cin>>a>>b;
			p[i]=a;
			w[i]=b;
		}
		cin>>g;
		int ans=0;
		while(g--){
			cin>>W;
			ans+=knapsack(W,w,p,n);
		}
		cout << ans << "\n";
	}
	return 0;
}