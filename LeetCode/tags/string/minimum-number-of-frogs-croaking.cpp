
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char,int> idx{{'c',0}, {'r',1}, {'o',2}, {'a',3}, {'k',4}};
        int frogs=0, max_frogs=0, counter[5]={};
        for(char& c:croakOfFrogs) {
            int n = idx[c];
            ++counter[n]; // increase frogs singing current char
            if(n==0) max_frogs = max(max_frogs, ++frogs); // new frog started
            else if(--counter[n-1]<0) return -1;  // decrease count of frogs singing previous char, if no frog sang prev, return -1
            else if(n==4) --frogs; // frog completed singing. decrease in simultaneous frogs
        }
        return frogs==0 ? max_frogs : -1; // check if at least one frog did not complete singing till 'k'
    }
};


