/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
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

char first_non_repeating(string s) {
    map<char, int> m;
    m.clear();
    for(int i=0;i<s.size();i++) {
        m[s[i]]++;
    }
    for(auto x=m.begin(); x!=m.end(); x++){
        if(x->second==1) {
            return x->first;
        }
    }
    return '\0';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    string s = "geeksforgeeks";
    char c = first_non_repeating(s);
    if(c=='\0') {
        cout << "Either string is empty or all the chars are repeating" << endl;
    } else {
        cout << "first non-repeating character is " << c << endl;
    }
    return 0;
}


