#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> not_visited (wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int steps=1;
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                string f = q.front(); q.pop();
                if(f==endWord)
                    return steps;
                not_visited.erase(f); // visited
                for(int i=0;i<f.size();i++) {
                    char prev=f[i];
                    for(int j=0;j<26;j++) {
                        f[i] = 'a' + j;
                        if(not_visited.find(f) != not_visited.end()) {
                            q.push(f);
                            not_visited.erase(f); // visited
                        }
                    }
                    f[i]=prev;
                }
            }
            ++steps;
        }
        return 0;
    }
};


