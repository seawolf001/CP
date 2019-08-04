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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    map<int, int> voters;
    int id;
    for(int i=0;i<(n1+n2+n3);i++) {
        cin>>id;
        voters[id]++;
    }
    string ans="";
    int count=0;
    for (auto it=voters.begin(); it!=voters.end(); it++) {
        if (it->second >= 2) {
            ans += to_string(it->first) + "\n";
            count++;
        }
    }
    ans = (to_string(count)) + "\n"+ ans;
    cout << ans;
    return 0;
}

