#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll unsigned long long int
using namespace std;
vector<ll> fibonacci;
/*void multiply(int F[2][2], int M[2][2]) 
{ 
  int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0]; 
  int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1]; 
  int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0]; 
  int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1]; 
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
}

void power(int f[2][2], int n){
    if(n== 0 || n==1){
        return;
    }
    int m[2][2] = {{1,1},{1,0}};
    power(f,n/2);
    multiply(f,f);
    if(n%2==1) multiply(f,m);
}
ll fib(int n){
    int f[2][2]={{1,1},{1,0}};
    if(n==0) return 0;
    power(f,n-1);
    return f[0][0];
}
ll scf(ll a, ll b){
    if(a%2==0 && b%2==0) return 2;
    for(ll i=3; i<=b; i+=2){
        if(a%i==0 && b%i==0) return i;
    }
    return 1;
}
void pre_process(){
    fibonacci.clear();
    ll i=0;
    ll f=0;
    fibonacci.push_back(f);
    while(f<1e18){
        i++;
        f = fib(i);
        fibonacci.push_back(f);
    }
}*/
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    // pre_process();
    int n=0,k=0; cin>>n;
    while(n--){
        cin>>k;
        if(k==2 || k==3){
            cout << k << " " << k << "\n";
        } else {
            
        }
        /*bool found=false;
        int i;
        for(i=2;i<=k;i++){
            ll f = fibonacci[i];
            ll d = scf(f,k);
            if(d!=1){
                cout << f << " " << d << "\n";
                found=true;
                break;
            }
        }
        if(!found){
            i=k+1;
            ll f = fibonacci[i];
            while(f%k!=0){
                i++;
                f=fibonacci[i];
            }
            cout << f << " " << k << "\n";
        }*/
    }
    return 0;
}
