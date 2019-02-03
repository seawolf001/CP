#include<iostream>
#include<cstring>
#define fin freopen("in.imp", "r", stdin)
#define fout freopen("out.imp", "w", stdout)
using namespace std;

int coins[] = {50, 25,10,5,1};
int s=0;

int main(){
	while(cin>>s){
		int dp[s+1];
		memset(dp, 0, sizeof dp);
		dp[0]=1;
		for(int i=0;i<5;i++){
			for(int j=coins[i];j<=s;j++){
				dp[j]+=dp[j-coins[i]];
			}
		}
		cout << dp[s]<< "\n";
	}
	return 0;
}