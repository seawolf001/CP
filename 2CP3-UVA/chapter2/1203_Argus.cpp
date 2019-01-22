#include <iostream>
#include <queue>
using namespace std;

string in="";
int q=0;
int p=0;
int k=0;

int main()
{
	priority_queue<pair<int, pair<int, int>>> _queue;
	while(cin>>in, in!="#"){
		cin >> q >> p;
		_queue.push(make_pair(-1*p, make_pair(-1*q, -1*p)));
	}
	cin >> k;
	while(k--){
		auto x = _queue.top();
		_queue.pop();
		cout << -(x.second.first) << "\n";
		
		int original = x.second.second;
		int id = x.second.first;
		
		int nextTime=  x.first + original;
		_queue.push(make_pair(nextTime,  make_pair(id, original)));
	}
	return 0;
}