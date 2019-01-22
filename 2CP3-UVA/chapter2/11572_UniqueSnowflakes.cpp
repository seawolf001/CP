#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
using namespace std;

long N=0;
long n=0;
map<long, long> _map;

int main(){
	cin >> N;
	while(N--){
		_map.clear();
		cin >> n;
		long so_far=0;
		long maximum=0;
		long curr=0;
		long collision=0;
		for(int i=1;i<=n;i++) {
			cin >> curr;
			if(_map[curr]!=0) {
				collision = max(collision, _map[curr]);
				so_far = i- collision -1;
			}
			_map[curr]=i;
			so_far++;
			if(so_far > maximum) maximum = so_far;
		}
		cout << maximum << "\n";
	}
	return 0;
}