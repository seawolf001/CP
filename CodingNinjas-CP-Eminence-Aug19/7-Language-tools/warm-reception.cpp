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
    int n;
    cin>>n;
    int* arr=new int[n];
    int* dep=new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cin>>dep[i];
    vector<pair<int, char>> v;
    for(int i=0;i<n;i++) {
        v.push_back(make_pair(arr[i], 'a'));
        v.push_back(make_pair(dep[i], 'd'));
    }
    sort(v.begin(), v.end());
    int max=0, curr=0;
    for(auto it=v.begin(); it!=v.end(); it++) {
        if((*it).second=='a') curr++;
        else curr--;
        if (curr>max) max=curr;
    }
    cout << max << "\n";
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

