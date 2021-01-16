#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(string &w: words) mp[w]++;
        auto comparator = [&](const string &s1, const string &s2) {
                        if(mp[s1]==mp[s2])
                            return s1 < s2;
                        return mp[s1] > mp[s2];
                    };
        priority_queue<string, vector<string>, decltype(comparator)> minh(comparator);
        for(auto &x:mp) {
            minh.push(x.first);
            if(minh.size()>k) minh.pop();
        }
        vector<string> vs;
        while(!minh.empty()) vs.push_back(minh.top()), minh.pop();
        sort(vs.begin(), vs.end(), [&](string &s1, string s2) {
                                        if(mp[s1]==mp[s2])
                                            return s1 < s2;
                                        return mp[s1] > mp[s2];
                                    });
        return vs;
    }
};


