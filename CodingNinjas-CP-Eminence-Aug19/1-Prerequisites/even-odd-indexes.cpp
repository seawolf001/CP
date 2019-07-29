#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=0,x=0;
    cin>>n;
    int s1=0,s2=0;
    for(int i=0;i<n;i++){
        cin>>x;
        if(i%2==0 && x%2==0) s1+=x;
        else if(i%2==1 && x%2==1) {
            s2+=x;
        }
    }
    cout << s1 << " " << s2;
    return 0;
}
