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

void removeConsecutiveDuplicates(char s[]) {
    if (s[0]=='\0') return;
    if (s[0]==s[1]) {
        int i=0;
        for(;s[i]!='\0';i++) {
            s[i]=s[i+1];
        }
        removeConsecutiveDuplicates(s);
    }
    removeConsecutiveDuplicates(s+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    char s[1005];
    cin>>s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
    return 0;
}

