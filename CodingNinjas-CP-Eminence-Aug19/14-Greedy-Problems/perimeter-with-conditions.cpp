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

bool comparator(const int x, const int y) {
    return x > y;
}

bool not_degenerate(int a, int b, int c) {
    return (a+b>c) && (a+c>b) && (b+c>a);
}

void triangle(int * arr, int n) {
    sort(arr, arr+n, comparator);
    int i=0,j=0,k=0,a=0,b=0,c=0;
    for (i=0;i<n-2;i++) {
        for(j=i+1;j<n-1;j++){
            for(k=j+1;k<n;k++){
                a = arr[i]; b = arr[j]; c = arr[k];
                if(not_degenerate(a,b,c)) {
                    cout << c << " " << b << " " << a << endl;
                    return;
                }
            }
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n; cin>>n;
    int * arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    triangle(arr, n);
    delete[] arr;
    return 0;
}


