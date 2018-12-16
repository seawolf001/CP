#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int arr[26];
int main(){
    memset(arr, 0, 26);
    char ch;
    int c=0;
    while((ch=getchar())!='\n') arr[ch-'a']++;
    for(int i=0;i<26;i++){
        cout << i << " " << arr[i] << endl;
    }
    set<int>s; 
    for(int i=0;i<26;i++){
        if(arr[i]!=0) s.insert(arr[i]);
        if(arr[i]==1) c++;
    }
    if(c>1 || s.size()>=2) cout << "NO";
    else cout <<"YES";
    return 0;
} 