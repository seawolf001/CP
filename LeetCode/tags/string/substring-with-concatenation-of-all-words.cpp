#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), word_length = words[0].size(), num_words = words.size();
        unordered_map<string, int> freq;
        for(string &s: words) freq[s]++;
        vector<int> ans;
        for(int i=0;i < n-word_length*num_words+1; i++) {
            unordered_map<string, int> counter; int matched=0;
            for(int j=0;j<num_words;j++) {
                string w = s.substr(i+j*word_length, word_length);
                if(freq.find(w)==freq.end()) break;
                counter[w]++;
                if(counter[w]>freq[w]) break;
                ++matched;
            }
            if(matched==num_words) ans.push_back(i);
        }
        return ans;
    }
};

