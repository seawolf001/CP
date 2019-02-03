#include<iostream>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<cmath>
#define FIXED_FLOAT(x,n) std::fixed <<std::setprecision(n)<<(x)
using namespace std;

int _sort(int a, int b){
	return a>b;
}

int main(){
	int c=0,s=0,tc=0,t=0,sum=0;
	double avg=0, imb=0;
	while(cin>>c>>s){
		++tc;
		int arr[2*c];
		sum=0;
		imb=0;
		memset(arr, 0, sizeof arr);
		for(int i=0;i<s;i++){
			cin>>t;
			arr[i]=t;
			sum+=t;
		}
		sort(arr, arr + 2*c, _sort);
		avg = (double)(sum*1.0/c);
		cout << "Set #" << tc;
		if(s<=c){
			int b=0;
			for(int i=2*c-1;i>=0;i--){
				if(arr[i]) {
					cout << "\n " << b++ << ": "<< arr[i];
					imb += fabs((double)(arr[i]+arr[2*c-i-1]-avg));
				}
			}
			for(;b<c;b++) cout << "\n " << b << ": ";
		} else {
			for(int i=0; i<c;i++){
				cout << "\n " << i << ": ";
				if(arr[2*c-1-i]) {
					cout << " " << arr[2*c-1-i];
				}
				if(arr[i]){
					cout << " " << arr[i];
				}
				imb += fabs((double)(arr[i]+arr[2*c-i-1])-avg);
			}
		}
		cout << "\nIMBALANCE = " << FIXED_FLOAT(imb,5) << "\n\n";
	}
	return 0;
}