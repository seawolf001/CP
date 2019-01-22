/*
* to flip nth  bit in k  ==> k^(1<<n)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int N=0;
	while(scanf("%d", &N)==1){
		int corners = pow(2,N);
		int weight[corners];
		for(int i=0;i<corners;i++){
			int x=0; 
			cin >> x;
			weight[i]=x;
		}
		int potency[corners];

		for(int i=0;i<corners;i++) 
			potency[i]=0;

		for(int i=0;i<corners;i++){
			for(int j=0;j<N;j++){
				int index = i^(1<<j);
				potency[i]+=weight[index];
			}
		}
		int max=0;
		for(int i=0;i<corners;i++){
			for(int j=0;j<N;j++){
				int index=i^(1<<j);
				if(potency[i]+potency[index]>max) max = potency[i]+potency[index]; 
			}
		}
		cout << max << "\n";
	}
	return 0;
}