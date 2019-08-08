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

void FindTriplet(int arr[], int n, int x) {
    sort(arr,arr+n);
    for(int i=0;i<n-2;i++){
        int j=i+1;
        int k=n-1;
        while(j<k){
            int curr=arr[i]+arr[j]+arr[k];
            if(curr==x) {
                cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                j++;
                k--;
            } else if(curr<x) {
                j++;
            } else {
                k--;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n,x;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>x;
    FindTriplet(arr,n,x);
    return 0;
}

