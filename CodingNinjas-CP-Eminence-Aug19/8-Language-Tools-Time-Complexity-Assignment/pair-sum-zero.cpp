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

void PairSum(int *arr, int n) {
    unordered_map<int, int> m;
      for (int i = 0; i < n; i++) {
        int x=arr[i];
        int y=-1*x;
        if (m.find(y) != m.end()) {
            int count = m[y];
            for (int j = 0; j < count; j++){
                if (x>y) cout << y << " " << x << "\n";
                else cout << x << " " << y << "\n";
            }
        }
        m[arr[i]]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */

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

