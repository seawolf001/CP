/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

struct Worker {
    int time=0;
    int cost=0;
    int speed=0;
};

bool comparator(const Worker x, const Worker y) {
    if(x.time == y.time) {
        if(x.speed == y.speed) {
            return x.cost < y.cost;
        } else {
            return x.speed > y.speed;
        }
    } else {
        return x.time < y.time;
    }
}

long long fractional_knapsack(Worker * arr, int n, int d) {
    sort(arr, arr+n, comparator);
    long long currArea = 0, totalArea = 0;
    long long mincost = 0;
    int bestSpeed = 0 ;
    int lastTime = arr[0].time;
    for (int i=0;i<n;i++) {
        currArea = bestSpeed * 1LL * (arr[i].time - lastTime);
        totalArea += currArea;
        if(totalArea >= d) { break; }
        if(arr[i].speed > bestSpeed){
            bestSpeed = arr[i].speed;
            mincost += arr[i].cost;
        }
        lastTime = arr[i].time;
    }
    return mincost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n; long d; cin>> n >> d;
    Worker * arr = new Worker[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i].time >> arr[i].cost >> arr[i].speed;
    }
    cout << fractional_knapsack(arr, n ,d) << endl;
    delete[] arr;
    return 0;
}


