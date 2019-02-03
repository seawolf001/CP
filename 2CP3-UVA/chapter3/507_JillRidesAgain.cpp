#include <iostream>
using namespace std;

int T=0,n=0,curr=0,mx=0,s=0,e=0,t=0,c=0;

int main(){
	cin>>T;
	for(int k=1;k<=T;k++){
		cin>>n;
		curr=0,mx=0;
		s=0,e=0,c=0;
		for(int i=1;i<n;i++){
			cin>>t; 
			curr+=t;
			if(curr<0){
				curr=0;
				c=i;
			} else if(curr>=mx){
				if(curr>mx || (curr==mx && i-c>e-s)){
					s=c;
					e=i;
					mx=curr;
				}
			}
		}
		if(mx>0){
			cout << "The nicest part of route " << k << " is between stops " << (s+1) << " and " << (e+1) << "\n";
		} else {
			cout << "Route "<<k<<" has no nice parts\n";
		}
	}
	return 0;
}