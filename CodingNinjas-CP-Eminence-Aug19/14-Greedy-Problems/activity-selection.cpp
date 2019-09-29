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

struct Activity {
    int s=0;
    int f=0;
};

bool comparator(const Activity a1, const Activity a2) {
    return a1.f < a2.f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n=0; cin >> n;
    Activity * arr = new Activity[n];
    for (int i=0;i<n;i++)  {
        cin >> arr[i].s;
        cin >> arr[i].f;
    }
    sort(arr, arr+n, comparator);
    int count=1;
    int k=0;
    for(int i=1;i<n;i++) {
        if(arr[i].s > arr[k].f) {
            count ++;
            k = i;
        }
    }
    cout << count << endl;
    delete[] arr;
    return 0;
}


