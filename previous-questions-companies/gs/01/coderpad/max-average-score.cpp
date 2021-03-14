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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    string scores[4][2] = {{"jerry", "65"}, {"bob", "91"}, {"jerry", "23"}, {"Eric", "83"}};
    unordered_map<string, pair<int, int>> m;
    for (int i=0;i<4; i++){
        if(m.find(scores[i][0]) != m.end()) {
            m[scores[i][1]].first += stoi(scores[i][1]);
            m[scores[i][1]].second += 1;
        } else {
            m[scores[i][0]] = make_pair(stoi(scores[i][1]), 1);
        }
    }
    float avg=0, max_avg=0;
    for(auto x=m.begin(); x!=m.end(); x++) {
        avg = ((*x).second.first)/((*x).second.second);
        max_avg = max(max_avg, avg);
    }
    cout << max_avg << endl;
    return 0;
}


