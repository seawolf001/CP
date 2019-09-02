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

int substrings(string s, string* arr) {
    if(s.empty()) {
        arr[0] = "";
        return 1;
    }
    string s1 = s.substr(1);
    int num = substrings(s1, arr);
    for(int i=0;i<num;i++) {
        arr[i+num] = s[0]+arr[i];
    }
    return 2*num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    string s; cin>>s;
    string* arr = new string[1000];
    int num = substrings(s, arr);
    sort(arr, arr+num);
    for(int i=0;i<num;i++) { cout << arr[i] << endl; }
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

