#include <iostream>
#include <queue>
using namespace std;

long N=0, n=0, cost=0, sum=0;

int main(){
	while(cin>>N, N!=0){
		priority_queue<long> q;
		while(N--){
			cin >> n; 
			q.push(-1*n);
		}
		cost=sum=0;
		while(q.size()!=1){
			long a = q.top(); q.pop();
			long b = q.top(); q.pop();
			sum = (a+b);
			cost += -1*sum;
			q.push(sum);
		}
		cout << cost << "\n";
	}
	return 0;
}