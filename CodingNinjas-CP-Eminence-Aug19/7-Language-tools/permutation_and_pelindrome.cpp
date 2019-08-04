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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int T=0;
    cin >> T;
    string s;
    int n=0;
    map<int, vi> occur;
    while(T--) {
        bool valid=true;
        cin>>s;
        n = s.size();
        occur.clear();
        int odd_char=0;
        for(int i=0;i<n;i++) {
            occur[(s[i]-'a')+1].push_back(i+1);
        }
        vi ans(n);
        vi odd;
        vi even;
        int s=0, e=n-1;
        for(auto it=occur.begin(); it!=occur.end(); it++) {
            vi curr=it->second;
            int freq = curr.size();
            if(freq%2!=0) {
                int curr_odd_char = (it->first);
                if(odd_char != 0 && odd_char != curr_odd_char){
                    valid=false;
                } else {
                    odd_char = curr_odd_char;
                    odd=curr;
                }
            } else {
                even.insert(even.end(), curr.begin(), curr.end());
            }
        }
        if(valid) {
            vi::iterator it;
            for (it=even.begin(); it!=even.end();) {
                ans[s++]=*it;
                it++;
                if (it!=even.end()) {
                    ans[e--]=*it;
                    it++;
                }
            }
            for(it=odd.begin();it!=odd.end();) {
                ans[s++]=*it;
                it++;
                if (it!=odd.end()) {
                    ans[e--]=*it;
                    it++;
                }
            }
            for (it=ans.begin(); it!=ans.end(); it++) {
                cout << *it << " ";
            }
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}

