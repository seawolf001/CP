#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,x,y;
    cin>>n;
    int winner=1,maxlead=0;
    int cs1=0,cs2=0,lead=0,w=1;
    while(n--) {
        cin>>x>>y;
        cs1+=x;
        cs2+=y;
        lead=0;
        if (cs1>=cs2){
            w=1;
            lead = cs1-cs2;
        } else {
            w=2;
            lead=cs2-cs1;
        }
        if(lead>maxlead){
            maxlead=lead;
            winner = w;
        }
    }
    cout << winner << " " << maxlead ;
    return 0;
}
