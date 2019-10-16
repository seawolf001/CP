/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
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
    int n, k; cin>>n>>k;
    int * arr = new int[n];
    for (int i=0;i<n;i++) cin>>arr[i];
    int max = *(max_element(arr, arr+n));
    int min = *(min_element(arr, arr+n));
    if((max-min)<=k){
        cout << (max-min) << endl;
    } else {
        int avg = (max+min)/2;
        for(int i=0;i<n;i++) {
            if(arr[i] > avg) {
                arr[i] -= k;
            } else {
                arr[i] += k;
            }
        }
        cout << ((*max_element(arr, arr+n)) - (*min_element(arr, arr+n))) << endl;
    }
    return 0;
}


