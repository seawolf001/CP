#include<iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

string arr[5];
map<string, int> _map;
int n=0;
int _max=0;

int main(){
	while(cin>>n, n!=0){
		_map.clear();
		for(int i=0;i<5;i++) arr[i]="";
		_max=0;
		while(n--){
			cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
			sort(arr, arr+5);
			string s = arr[0] + " " + arr[1] + " " + arr[2] + " " + arr[3] + " " + arr[4];
			if(_map[s]==0) _map[s]=1;
			else _map[s]=_map[s]+1;
		}

		for(auto x= _map.begin(); x!=_map.end(); x++){
			if((x->second) > _max) _max = (x->second);
		}
		int count=0;
		for(auto x= _map.begin(); x!=_map.end(); x++){
			if((x->second) == _max){
				count+=_max;
			}
		}
		cout << count << "\n";
	}
	return 0;
}