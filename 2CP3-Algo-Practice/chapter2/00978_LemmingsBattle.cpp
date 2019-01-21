#include<iostream>
#include<set>
#include <vector>
using namespace std;

int N=0;
int bt=0, g=0, b=0, x=0; 
multiset<int, greater<int>> green, blue;
vector<int> gv, bv;

int main(){
	/*freopen("1in.txt", "r", stdin);
    freopen("1out.txt", "w", stdout);*/
	bool first=true;
	cin>>N;
	while(N--){
		if(!first) {
			cout<<"\n";
		} else {
			first=false;
		}
		green.clear();
		blue.clear();
		cin>>bt>>g>>b;
		for(int i=0;i<g;i++){
			cin>>x;
			green.insert(x);
		}
		for(int i=0;i<b;i++){
			cin>>x;
			blue.insert(x);
		}
		while(!green.empty() && !blue.empty()){
			gv.clear();
			bv.clear();
			for(int i=0;i<bt;i++){
				if(green.empty() || blue.empty()) break;
				auto a1=green.begin();
				auto a2=blue.begin();
				// cout << "green=" << *a1 << " blue=" << *a2 << "\n";
				int diff = *a1-*a2;
				if(diff>0) 
					gv.push_back(diff);
				else if(diff<0) 
					bv.push_back(-1*diff);
				green.erase(a1);
				blue.erase(a2);
			}
			for(auto x=gv.begin(); x!=gv.end(); x++) green.insert(*x);
			for(auto x=bv.begin(); x!=bv.end(); x++) blue.insert(*x);

			if(green.empty() && blue.empty()){
				cout << "green and blue died\n";
				break;
			} else if(green.empty()){
				cout << "blue wins\n";
				for(auto x=blue.begin(); x!=blue.end(); x++){
					cout << *x << "\n";
				}
				break;
			} else if(blue.empty()){
				cout << "green wins\n";
				for(auto x=green.begin(); x!=green.end(); x++){
					cout << *x << "\n";
				}
				break;
			}
		}
	}
}