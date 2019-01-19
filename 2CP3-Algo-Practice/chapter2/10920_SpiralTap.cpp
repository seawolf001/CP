#include <bits/stdc++.h>
using namespace std;
int s,p;
int main()
{
	/*
	* size s <= 10^5
	* p = spiral coordinate
	*/
	vector<long long> v;
	for(int i=0;i<10e5;i++){
		if(i%2!=0){
			v.push(pow(i, 2));
		}
	}
	while(scanf("%d %d", &s, &p)==2, s!=0, p!=0){
		/*int l = lower_bound(v.begin(), v.end(), p) - v.begin();
		int r = upper_bound(v.begin(), v.end(), p) - v.begin();
		int diff1 = abs(p-v[l]);
		int diff2 = abs(p-v[r]);
		int c=0;
		if(diff1>diff2){
			c = sqrt(v[l]);
		} else{
			c = sqrt(v[r]);
		}*/
		
	}
	return 0;
		}
}