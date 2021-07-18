#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> occur;
        int n = s.size();
        for(int i=0;i<n;i++)
            occur[s[i]] = i;
        vector<int> ans;
        for(int i=0;i<n;) {
            int last = occur[s[i]], start=i; // Need to consider till last occurance of this char
            while(i<=last) {
                last = max(last, occur[s[i]]); // consider till last of other chars if came in between.
                ++i;
            }
            ans.push_back(i-start); // append the distance.
        }
        return ans;
    }
};

