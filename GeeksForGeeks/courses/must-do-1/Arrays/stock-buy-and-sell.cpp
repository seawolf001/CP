/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int t=0; cin >> t;
    while(t--) {
        int n, i=0; cin>> n;
        int arr[n];
        for(i=0;i<n;i++) cin>>arr[i];
        i=0;
        int count=0;
        while(i<n-1) {
            while((i<n-1) && arr[i+1]<=arr[i]) i++;
            if(i==n-1) {
                if(count==0) {
                    cout << "No Profit";
                }
                break;
            }
            int b=i++;
            while((i<n) && (arr[i]>=arr[i-1])) i++;
            int s=i-1;
            count++;
            cout << "(" << b << " " << s << ") ";
        }
        cout << endl;
    }
    return 0;
}


