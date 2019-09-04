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
vector<string> split(const string& s, char delim);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int t; cin>>t;
    while(t--) {
        int n,m,x,y,p;
        cin>>n>>m;
        vector<pair<int, int>> intervals;
        for (int i=0;i<n;i++) {
            cin>>x>>y;
            intervals.push_back(make_pair(x,y));
        }
        sort(intervals.begin(), intervals.end());
        for(int i=0;i<m;i++) {
            cin>>p;
            int ans;
            int pos = lower_bound(intervals.begin(), intervals.end(), make_pair(p,0)) - intervals.begin();
            if (pos == 0) {
                ans = intervals[0].first - p;
            } else if (intervals[pos-1].second > p){
                ans = 0;
            } else if (pos < intervals.size()) {
                ans = intervals[pos].first - p;
            } else {
                ans = -1;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
vector<string> split(const string& s, char delimiter) {
   vector<string> tokens;
   string token;
   stringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter)) {
      tokens.push_back(token);
   }
   return tokens;
}

