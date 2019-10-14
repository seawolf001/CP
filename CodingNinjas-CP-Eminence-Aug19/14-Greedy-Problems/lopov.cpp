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

struct Item { int value, mass; };

bool comparator(const Item x, const Item y) {
    if (x.value == y.value)
        return x.mass < y.mass;
    return x.value > y.value;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n,k,w; cin>>n>>k;
    Item * arr = new Item[n];
    for(int i=0;i<n;i++) { cin >> arr[i].mass >> arr[i].value; }
    multiset<int> m;
    for(int i=0;i<k;i++) { cin>>w; m.insert(w); }
    sort(arr, arr+n, comparator);
    long long ans=0;
    for(int i=0;i<n;i++){
        if(m.empty()) break;
        if(m.lower_bound(arr[i].mass) != m.end()) {
            ans += arr[i].value;
            m.erase(m.lower_bound(arr[i].mass));
        }
    }
    cout << ans<< endl;
    return 0;
}


