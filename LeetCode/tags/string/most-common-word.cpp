#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> f; int i=0, n=paragraph.size();
        while(i < n) {
            while(i<n && !(az(paragraph[i])||AZ(paragraph[i]))) i++;
            string w="";
            while(i<n && (az(paragraph[i])||AZ(paragraph[i]))) w+=paragraph[i++];
            transform(w.begin(), w.end(), w.begin(), ::tolower);
            bool not_banned = find(banned.begin(), banned.end(), w)==banned.end();
            if(not_banned && w!="") f[w]++;
        }
        int c=INT_MIN; string ans="";
        for(auto &p:f) {
            if(p.second > c) {
                c = p.second;
                ans=p.first;
            }
        }
        return ans;
   }
};


