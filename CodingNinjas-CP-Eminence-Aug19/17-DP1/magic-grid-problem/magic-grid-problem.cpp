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

int min_health(int ** g, int m, int n) {
    g[m-1][n-1]=1;
    for(int i=n-2; i>=0; i--) {
        g[m-1][i] = g[m-1][i+1] - g[m-1][i];
        if(g[m-1][i] <= 0) g[m-1][i]=1;
    }
    for(int i=m-2; i>=0; i--) {
        g[i][n-1] = g[i+1][n-1] - g[i][n-1];
        if(g[i][n-1] <= 0) g[i][n-1] = 1;
    }
    for(int i=m-2; i>=0; i--) {
        for(int j=n-2; j>=0; j--) {
            g[i][j] = min(g[i+1][j], g[i][j+1]) - g[i][j];
            if(g[i][j] <=0 ) g[i][j] =1 ;
        }
    }
    return g[0][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int t=0; cin>>t;
    while(t--) {
        int m,n; cin >> m >> n;
        int ** g = new int * [m];
        for(int i=0;i < m; i++) { g[i] = new int[n]; }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                cin>>g[i][j];
            }
        }
        cout << min_health(g, m, n) << endl;
        for(int i=0;i<m; i++) delete g[i];
        delete [] g;
    }
    return 0;
}


