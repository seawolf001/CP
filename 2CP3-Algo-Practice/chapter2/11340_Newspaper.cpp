#include <bits/stdc++.h>
using namespace std;
int main(){
	int test; cin >> test;
	unsigned int arr[256];
	while(test--){
		for(int i=0;i<256;i++) arr[i]=0;
		int k; 
		cin >> k;
		char c; 
		int value;
		while(k--){
			cin >> c >> value;
			arr[c-'\0']=value;
		}
		cin >> k;
		cin.ignore();
		long cents=0;
		for(int j=0;j<k;j++){
			string line="";
			getline(cin, line);
			for(int i=0;i<line.size();i++){
				cents += arr[line[i]-'\0'];
			}
		}
		float dollars = (float)((cents*1.0)/(100));
		printf("%0.2lf$\n",dollars);
	}
	return 0;
}