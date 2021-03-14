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

bool comparator(int x, int y) {
    string a = to_string(x);
    string b = to_string(y);
    return (a+b) > (b+a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    vector<int> arr;
    arr.push_back(54); arr.push_back(546); arr.push_back(548); arr.push_back(60);
    sort(arr.begin(), arr.end(), comparator);
    for(auto x = arr.begin(); x!=arr.end(); x++) { cout << *x; }
    return 0;
}


