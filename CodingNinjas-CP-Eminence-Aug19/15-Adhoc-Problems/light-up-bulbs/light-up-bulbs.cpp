/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n,x,y; cin >> n >> x >> y;
    string s; cin >> s;
    long groups = s[0] == '0' ? 1 : 0;
    for(int i=1;i<n;i++) {
        if (s[i-1]=='1' && s[i]=='0') groups++;
    }
    cout << ((groups-1)*min(x,y)+y) << endl;
    return 0;
}
