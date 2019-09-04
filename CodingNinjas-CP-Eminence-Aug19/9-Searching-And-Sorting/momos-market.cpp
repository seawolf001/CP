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
    int n,q,X;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) { cin>>arr[i]; }
    cin>>q;
    while(q--) {
        cin>>X;
        ll saved=0;
        int count=0;
        for(int i=0;i<n;i++) {
            if (X < arr[i]) {
                saved += X;
                break;
            } else {
                count++;
                X -= arr[i];
            }
        }
        cout << count << " " << saved << "\n";
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

