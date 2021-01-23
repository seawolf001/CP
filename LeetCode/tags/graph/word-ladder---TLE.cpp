// #include<bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
private:
    unordered_map<string, list<string>> adj;
    int bfs(string src, string dest) {
        queue<pair<string, int>> q;
        q.push(make_pair(src,1));
        unordered_map<string, bool> vis;
        vis[src]=true;
        while(!q.empty()) {
            auto f = q.front(); q.pop();
            if(f.first==dest) return f.second+1;
            for (auto next:adj[f.first]) {
                if(!vis[next]) {
                    vis[next]=true;
                    q.push(make_pair(next, f.second+1));
                }
            }
        }
        return INT_MAX;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        adj.clear();
        int n = wordList.size();
        vector<string> sources;
        for(int i=0;i<n;i++) {
            int diff=0;
            for(int k=0;k<beginWord.size();k++) {
                if(beginWord[k]!=wordList[i][k])
                    ++diff;
            }
            if(diff<=1)  sources.push_back(wordList[i]);
            for(int j=i+1;j<n;j++) {
                diff = 0;;
                for(int k=0;k<wordList[i].size(); k++) {
                    if (wordList[i][k]!=wordList[j][k])
                        ++diff;
                }
                if(diff==1) {
                    adj[wordList[i]].push_front(wordList[j]);
                    adj[wordList[j]].push_front(wordList[i]);
                }
            }
        }
        int ans=INT_MAX;
        for(string &src:sources) {
            int curr = bfs(src,endWord);
            ans = min(ans, curr);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
