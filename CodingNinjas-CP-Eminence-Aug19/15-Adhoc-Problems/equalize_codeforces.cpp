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

long equalize_cost(string x, string y, int n) {
    long cost = 0;
    for (int i=0;i<n;) {
        if (x[i] != y[i]) {
            if((i+1<n) && (x[i+1] != y[i+1]) && (x[i]!=x[i+1])) {
                cost ++;
                i += 2;
            } else{
                cost++;
                i++;
            }
        } else {
            i++;
        }
        if(i>=n) break;
    }
    return cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n; cin >> n;
    string x, y;
    cin >> x >> y;
    cout << equalize_cost(x, y, n) << endl;
    return 0;
}


