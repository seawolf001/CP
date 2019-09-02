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
vector<string> split(const string& s, char delim);

int partition(int arr[], int l, int r) {
    int p = arr[l];
    int cnt=0; int i,j;
    for(i=l+1;i<=r;i++) {
        if (arr[i]<=p) cnt++;
    }
    int tmp = arr[l+cnt];
    arr[cnt+l] = p;
    arr[l] = tmp;

    i=l; j=r;
    while(i<j) {
        if (arr[i] <= p) i++;
        else if (arr[j] > p) j--;
        else {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++; j--;
        }
    }
    return l+cnt;
}

void quick_sort(int arr[], int l, int r) {
    if (r<l) return;
    int c = partition(arr, l, r);
    quick_sort(arr, l, c-1);
    quick_sort(arr, c+1, r);
}

void quickSort(int arr[], int n) {
    if(n==0 || n==1) return;
    quick_sort(arr, 0, n-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    quickSort(arr,n);
    for(int i=0;i<n;i++) { cout << arr[i] << " "; }
    return 0;
}
vector<string> split(const string& s, char delimiter) {
   vector<string> tokens;
   string token;
   stringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter)) {
      tokens.push_back(token);
   }
   return tokens;
}

