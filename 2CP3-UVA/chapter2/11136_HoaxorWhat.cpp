#include <iostream>
#include <set>

using namespace std;
long cost=0;
int n=0, k=0, x=0;
multiset<int> s;

int main(){
	while(cin>>n, n!=0){
		s.clear();
		cost=0;
		while(n--){
			cin>>k;
			while(k--){
				cin	>> x;
				s.insert(x);	
			}
			auto _max = s.end();
			_max--;
			auto _min = s.begin();
			cost += (*_max-*_min);
			s.erase(_max);
			s.erase(_min);
		}
		cout << cost << "\n";
	}
}