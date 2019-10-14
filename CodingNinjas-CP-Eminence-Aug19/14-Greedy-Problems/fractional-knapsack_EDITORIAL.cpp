#include<bits/stdc++.h>
using namespace std;

#define rep(a,b) for(long i=a;i<b;i++)
#define ll long long

struct painter{
	int time, cost, speed;
};

bool comp(painter a, painter b) {
	if(a.time==b.time) {
        if(a.speed==b.speed)
            return a.cost<b.cost;
        return a.speed>b.speed;
    }
	return a.time < b.time;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n; ll d;
	cin >> n >> d;
	painter arr[n];
	rep(0, n) {
		cin >> arr[i].time >> arr[i].cost >> arr[i].speed;
	}
	sort(arr, arr+n, comp);
	ll area = 0, bestSpeed = 0, Cost = 0, lastTime = arr[0].time;
	for(int i=0;i<n;i++) {

		ll additional = bestSpeed * 1LL * (arr[i].time-lastTime);
		area += additional;
		if (area>=d) break;
		if(arr[i].speed>bestSpeed) {bestSpeed = arr[i].speed; Cost += arr[i].cost;}

		lastTime = arr[i].time;

	}
	cout << Cost;

	return 0;
}
