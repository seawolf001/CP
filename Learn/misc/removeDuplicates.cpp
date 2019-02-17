#include<bits/stdc++.h>
using namespace std;
string s="";
int main(){
    cin>>s;
    int mask=0;
    int n=s.size();
    int i=0,len=0;
    while(i<n){
        int x = s[i]-'a';
        int f = (1<<x);
        if((mask & f) == 0){
            // s[len++]='a'+x;
            cout << (char)('a'+x);
            mask = mask | f;
        }
        i++;
    }
    return 0;
}