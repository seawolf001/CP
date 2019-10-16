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

void lottery_number(int s, int d) {
    if (s==0 && d==1) cout << "0\n";
    else {
        int ans[d];
        s -= 1;
        ans[0] = 1;
        for (int i=d-1; i>0; i--){
            if (s>9){
                ans[i]=9;
                s -= 9;
            } else {
                ans[i] = s;
                s = 0;
            }
        }
        ans[0] += s;
        for (int i=0;i<d;i++){
            cout << ans[i];
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int s,d;
    cin >> s >> d;
    lottery_number(s,d);
    return 0;
}


