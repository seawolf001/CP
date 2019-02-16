#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
ll dp[10004][102];

void preprocess(){
    for(int i=0;i<=100;i++) dp[0][i]=1;
    for(int k=1;k<=100;k++){
        for(int i=1;i<=10000;i++){
            for(int j=1;j<=min(i,k);j++){
                dp[i][k] = (dp[i][k]+dp[i-j][k]) % mod;
            }
        }
    }
}
int main(){
    preprocess();
    int T=0,x=0,k=0;
    cin>>T;
    while(T--){
        cin>>x>>k;
        cout << dp[x][k] << "\n";
    }
    return 0;
}
