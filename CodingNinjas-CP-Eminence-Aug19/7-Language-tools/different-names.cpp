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
    /* Start writing from here */
    string s;
    getline(cin, s);
    vector<string> arr = split(s, ' ');
    map<string, int> freq;
    for(auto it=arr.begin(); it!=arr.end(); it++) {
        freq[*it]++;
    }
    bool found=false;
    for(auto it=freq.begin(); it!=freq.end(); it++) {
        int count = it->second;
        if (count > 1) {
            found = true;
            cout << it->first << " " << count << endl;
        }
    }
    if(!found) cout << "-1";
    return 0;
}
std::vector<std::string> split(const std::string& s, char delimiter) {
   std::vector<std::string> tokens;
   std::string token;
   std::stringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter)) {
      tokens.push_back(token);
   }
   return tokens;
}
