
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n = croakOfFrogs.size();
        vector<int> arr, dep;
        for(int i=0;i<n;i++) {
            if(croakOfFrogs[i]=='c') {
                arr.push_back(i);
            }
        }
        string croak="croak";
        for(int x:arr) {
            int m = 0,j=x;
            for(j=x;j<n;j++) {
                if(croak[m]==croakOfFrogs[j]) {
                    croakOfFrogs[j]='X';
                    if(++m==croak.size()) break;
                }
            }
            if(m!=croak.size()) return -1;
            else dep.push_back(j-1);
        }
        if(arr.size()!=dep.size()) return -1;
        for(int i=0;i<n;i++) {
            if(croakOfFrogs[i]!='X') return -1;
        }
        for(int i=0;i<arr.size();i++){cout << arr[i] << " " << dep[i]<<endl;}
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int concurrent=0,i=0,j=0,N=arr.size(),MAX=0;
        while(i<N && j<N) {
            if(arr[i]<=dep[j]) {
                concurrent++;
                i++;
            } else {
                concurrent--;
                j++;
            }
            MAX = max(MAX, concurrent);
        }
        return MAX;
    }
};

