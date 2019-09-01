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

vector<int>longestSubsequence(int *arr, int n){
    map<int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    int num=0,s=0;

}
typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;
typedef std::vector<string> vs;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vi ans=longestSubsequence(arr,n);
    for(auto it=ans.begin(); it!=ans.end(); it++) {
        cout << *it << " ";
    }
    return 0;
}
