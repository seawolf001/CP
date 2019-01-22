#include <bits/stdc++.h>
using namespace std;
int diff(int a, int b){
	return a>b ? a-b : b-a;
}
int main(){
	int n;
	while(scanf("%d", &n)==1){
		int curr, prev, size;
		size=n-1;
		int arr[size];
		for(int i=0;i<size;i++) arr[i]=0;
		bool first=true;
		while(n--){
			scanf("%d", &curr);
			if(first){
				prev=curr;
				first = false;
			} else{
				// printf("prev=%d curr=%d diff=%d\n",prev, curr, diff(prev, curr));
				arr[diff(prev, curr)-1]++;
				// printf("diff(prev, curr)=%d arr[diff(prev, curr)-1]=%d\n",\
				// 	diff(prev, curr), arr[diff(prev, curr)-1]);
				prev=curr;
			}		
		}
		bool jolly=true;
		for(int i=0;i<size;i++){
			// printf("arr[%d] is= %d \n",i,arr[i]);
			if(arr[i]!=1){
				jolly=false;
				break;
			}
		}
		if(jolly) printf("Jolly\n");
		else printf("Not jolly\n");
	}
}