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
    // sort(arr, arr+n);
    unordered_map<int,int> mp;
    int dp[n];
    memset(dp, 0, sizeof(dp));
    int maximum = INT_MIN;
    int index=-1;
    for (int i=0;i<n;i++){
        if(mp.find(arr[i]-1)!=mp.end()) {
            int l = mp[arr[i]-1]-1;
            dp[i] = 1+dp[l];
        } else {
            dp[i]=1;
        }
        mp[arr[i]] = i+1;
        if (maximum < dp[i]) {
            maximum = dp[i];
            index = i;
        }
    }
    vector<int> ans;
    for(int curr=arr[index]-maximum+1;
            curr<=arr[index]; curr++) {
        ans.push_back(curr);
    }
    return ans;
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
