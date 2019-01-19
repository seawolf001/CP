#include <bits/stdc++.h>
using namespace std;

int n, m;
int start, _end, repeat;
bool timeAxis[1000000];
bool conflict = false;

bool check(){
	for(int i=start; i<_end; i++){
		if(timeAxis[i]) 
			return true;
		timeAxis[i] = true;
	}
	return false;
}

int main(){
	while(true){
		cin >> n >> m;
		if(n==0 && m==0) break;
		conflict = false;
		
		for(int i=0;i<1000000;i++)
			timeAxis[i]=false;

		for(int i=0;i<n;i++){
			cin >> start >> _end;
			if(check())
				conflict = true;
		}
		for(int i=0;i<m;i++){
			cin >> start >> _end >> repeat;
			while(start < 1000000){
				if(conflict) break;
				if(check()) conflict = true;
				start += repeat;
				_end += repeat;
				if(_end > 1000000) _end = 1000000;
			}
		}
		if(conflict) cout << "CONFLICT\n";
		else cout << "NO CONFLICT\n";
	}
	return 0;
}