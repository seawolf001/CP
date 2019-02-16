#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll n=0,T=0,t=0;
ll arr[100005];

void subarr_xor(){
    if(n%2==0){
        cout << "0\n";
        return;
    }
    ll res=0;
    for (int i = 0; i<n; i+=2) {
        res ^= arr[i]; 
    }
    cout << res << "\n";
}

int main(){
    cin>>T;
    while(T--){
        cin>>n;
        memset(arr, 0, sizeof arr);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        subarr_xor();
    }
    return 0;
}
