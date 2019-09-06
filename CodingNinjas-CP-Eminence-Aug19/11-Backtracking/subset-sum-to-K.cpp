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

int subsetSumHelper(int arr[], int n, int output[][20], int curr, int const K, int& count) {
    if(curr == K) {

    }
}

int subsetSumToK(int arr[], int n, int output[][20], int K) {
    int count=0;
    if(K==0) return 0;
    int curr = 0, idx = 0;
    subsetSumHelper(arr, n, output, idx, curr, K, count);
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n=0; cin>>n;
    int arr[n]; memset(arr, 0, sizeof(arr));
    for(int i=0;i<n;i++) { cin>>arr[i]; }
    int K=0; cin>>K;
    int total = pow(2,n);
    int output[total][n];
    memset(output, INT_MAX, total*n*sizeof(int));
    count_subsets = subsetSumToK(arr,n,output,K);
    for(int i=0;i<count_subsets;i++) {
        for(int j=0;j<n;j++) {
            if(output[i][j] != INT_MAX) {
                cout << output[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}


