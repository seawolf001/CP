#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

int N=0;
int total=0;
string name="";
map<string, int> _map;

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	getchar(); // newline 
	getchar(); // blank line
	while(N--){
		total=0;
		_map.clear();
		while(getline(cin, name), name.length()!=0){
			if(_map[name]==0) _map[name]=1;
			else _map[name]=_map[name]+1;
			total++;
		}
		for(auto x = _map.begin(); x!=_map.end(); x++){
			cout << x->first << " ";
		 	printf("%.4lf\n", 100*(x->second)*1.0/(total));
		}
		if(N>0)printf("\n");
	}
	return 0;
}