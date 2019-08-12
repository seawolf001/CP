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

void Rotate(int arr[], int d, int n){
    while(d--){
        int x=arr[0];
        for(int i=1; i<n;i++){
            arr[i-1]=arr[i];
        }
        arr[n-1]=x;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n,d;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){ cin>>arr[i]; }
    cin>>d;
    Rotate(arr,d,n);
    for(int i=0;i<n;i++) {cout << arr[i] << " ";}
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

