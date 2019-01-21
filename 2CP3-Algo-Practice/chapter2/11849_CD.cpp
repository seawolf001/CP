#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n=0,m=0;
long num=0;
long common=0;
set<long> cds;

int main(){
	// vector<long> v;
	while(cin>>n>>m, n!=0 && m!=0){
		cds.clear();
		num=common=0;
		while(n--){
			cin>>num;
			cds.insert(num);
		}
		while(m--){
			cin>>num;
			if(cds.find(num)!=cds.end()) common++;
		}
		cout << common<< "\n";
		// v.push_back(common);
	}
	// printf("*************************************************\n");
	// for(auto x=v.begin(); x!=v.end(); x++) cout << *x << "\n";
	return 0;
}