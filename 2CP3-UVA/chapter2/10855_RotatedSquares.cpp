#include <bits/stdc++.h>
using namespace std;
int N,n;
int a,b,c,d;
string str="";

bool compare(int a, int b, vector<vector<int>> sArr, vector<vector<int>> bArr){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(sArr[i][j]!=bArr[i+a][j+b]){
				return false;
			}
		}
	}
	return true;
}
void rotate(vector<vector<int>> &sArr){
	for(int i=0;i<n/2;i++){
		for(int j=i;j<n-i-1;j++){
			int temp=sArr[i][j];
			sArr[i][j]=sArr[n-1-j][i];
			sArr[n-1-j][i]=sArr[n-1-i][n-1-j];
			sArr[n-1-i][n-1-j]=sArr[j][n-1-i];
			sArr[j][n-1-i]=temp;
		}
	}
}
int main(){	
	while(scanf("%d %d",&N,&n)==2, N!=0, n!=0){
		vector<vector<int>> bArr(N, vector<int>(N,0));
		vector<vector<int>> sArr(n, vector<int>(n,0));
		a=b=c=d=0;
		for(int i=0;i<N;i++){
			cin>>str;
			for(int j=0;j<N;j++){
				bArr[i][j]=str[j];
			}
		}
		for(int i=0;i<n;i++){
			cin>>str;
			for(int j=0;j<n;j++){
				sArr[i][j]=str[j];
			}
		}
		for(int i=0;i<N-n+1;i++){
			for(int j=0;j<N-n+1;j++){
				for(int k=0;k<4;k++){
					if(compare(i,j, sArr, bArr)){
						if(k==0) a++;
						else if(k==1) b++;
						else if(k==2) c++;
						else if(k==3) d++;
					}
					rotate(sArr);
				}
			}
		}
		cout << a << " " << b << " " << c << " " << d << "\n";
		a=b=c=d=0;
		str="";
		n=N=0;
	}
	return 0;
}