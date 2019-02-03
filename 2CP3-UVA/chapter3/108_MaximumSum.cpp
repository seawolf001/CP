#include <iostream>
#include <climits>
using namespace std;

int main(){
	/*freopen("in.imp", "r", stdin);
    freopen("out.imp", "w", stdout);*/
	int N=0;
	while(scanf("%d",&N)==1){
		int t=0,mx=INT_MIN;
		int dp[N][N];
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cin>>t;
				dp[i][j]=t;
				if(i>0) dp[i][j]+=dp[i-1][j];
				if(j>0) dp[i][j]+=dp[i][j-1];
				if(i>0 && j>0) dp[i][j]-=dp[i-1][j-1];
			}
		}		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				for(int k=i;k<N;k++){
					for(int l=j;l<N;l++){
						int curr=dp[k][l];
						if(i>0) curr-=dp[i-1][l];
						if(j>0) curr-=dp[k][j-1];
						if(i>0 && j>0) curr +=dp[i-1][j-1];
						mx=max(curr, mx);
					}
				}
			}
		}
		cout << mx << "\n";
	}
	return 0;
}
