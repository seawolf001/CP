/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;
typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;
typedef std::vector<string> vs;

struct Worker {
    int time=0;
    int cost=0;
    int speed=0;
};

bool comparator(const Worker x, const Worker y) {
    if(x.time == y.time) {
        double a = (double)(x.speed / x.cost);
        double b = (double)(y.speed / y.cost);
        if (a == b) {
            return x.cost < y.cost;
        } else {
            return a > b;
        }
    } else {
        return x.time < y.time;
    }
}

double fractional_knapsack(Worker * arr, int n, int d) {
    sort(arr, arr+n, comparator);
    long long currArea = 0;
    long long mincost = 0;
    int speed = 0 ;
    int time = 0;
    for (int i=0;i<n;i++) {
        if (currArea + arr[i].speed * arr[i].time <= d) {
            mincost += arr[i].cost;
            currArea += arr[i].speed * arr[i].time;
        }
    }
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


