#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<cstring>
#include <algorithm>
using namespace std;

/*because total minutes in a day are 24*60 */ 
int arr[1440]; 
int m=0, k=0;
int s1=0,s2=0,e1=0,e2=0;

void print(int p){
    if(p==0||p==1440) cout << "00 00";
    else {
        int h = p/60;
        int m = p%60;
        if(h<10) cout << "0" << h << " ";
        else cout << h << " ";
        if(m<10) cout << "0" << m;
        else cout << m ;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    memset(arr, 0, sizeof arr);
    cin>>m>>k;
    int s=0,e=0,f=0;
    for(int i=0;i<m;i++){
        cin>>s1>>s2>>e1>>e2;
        s = s1*60+s2;
        e = e1*60+e2;
        for(int i=s;i<e;i++) arr[i]=1;
    }
    s=e=f=0;
    int i=0,j=0;
    int h1=0,h2=0,m1=0,m2=0;
    while(i<1440){
        if(arr[i]==1) { i++; continue;}
        j=i;
        while(j<1440 && arr[++j]!=1);
        if((j-i)>=k){
            print(i);
            cout << " ";
            print (j);
            cout <<"\n";
        }
        i=j;
    }
    return 0;
}
