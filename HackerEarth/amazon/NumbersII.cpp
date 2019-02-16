#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b){
    if(a==0) return b;
    else if(b==0) return a;
    if(a>b) return gcd(a%b, b);
    else return gcd(b%a, a);
}

ll count(ll a, ll b, ll lcm, ll N){
    return N/a+N/b-N/lcm;
}

long long solve (long long a, long long b, long long n) {
   // Write your code here
   ll l=1, r=LLONG_MAX, mid;
   ll lcm = (a*b)/gcd(a,b);
   while(l<r){
       mid = l+(r-l)/2;
       if(count(a,b,lcm,mid) < n) l = mid+1;
       else r = mid;
   }
   return l;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        long long a;
        cin >> a;
        long long b;
        cin >> b;
        long long n;
        cin >> n;

        long long out_;
        out_ = solve(a, b, n);
        cout << out_;
        cout << "\n";
    }
}
