#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    string maximumTime(string time) {
        if(time[0]=='?' && time[1]=='?') time[0] = '2', time[1] = '3';
        else if(time[1]=='?') time[1] = time[0] == '2' ? '3' : '9';
        else if(time[0]=='?') time[0] = (time[1]-'0') <= 3 ? '2' : '1';

        if(time[3]=='?' && time[4]=='?') time[3]='5', time[4]='9';
        else if(time[3] == '?') time[3] = '5';
        else if(time[4] == '?') time[4] = '9';
        return time;
    }
};

