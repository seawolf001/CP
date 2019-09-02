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

void replace(char s[], char c1, char c2) {
    if (s[0] == '\0') { return;  }
    if (s[0] != c1) { replace(s+1, c1, c2); }
    else {
       s[0]=c2;
       replace(s+1,c1,c2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    char s[1000005];
    cin>>s;
    char c1,c2;
    cin>>c1>>c2;
    replace(s,c1,c2);
    cout << s << endl;
    return 0;
}
