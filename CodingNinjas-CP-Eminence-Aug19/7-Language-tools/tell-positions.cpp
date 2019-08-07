/*
 * Author: Jitendra Kumar (seawolf001)
 * Email: jitendra.iitp@gmail.com
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;
typedef std::vector<string> vs;

bool comparator(const pair<int, int> &p1, const pair<int, int> &p2) {
    if (p1.first == p2.first) return (p1.second < p2.second);
    return p1.first > p2.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n,m1=0,m2=0,m3=0;
    cin>>n;
    string name;
    vector<pair<int, int>> v;
    vector<string> names;
    for(int i=0;i<n;i++) {
        cin >> name >> m1 >> m2 >> m3;
        names.push_back(name);
        v.push_back(make_pair(m1+m2+m3, i));
    }
    sort(v.begin(), v.end(), comparator);
    int i=1;
    for(auto it=v.begin();it!=v.end();it++) {
        cout << (i++) << " " << names[((*it).second)] << "\n";
    }
    return 0;
}
