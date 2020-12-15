/* Jitendra Kumar */
// https://leetcode.com/problems/determine-if-two-strings-are-close/submissions/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int f1[26]={0}, f2[26]={0};
        multiset<int> s;

        for(char c: word1) {
            f1[c-'a']++;
        }
        for(int x: f1) {
            if(x!=0) {
                s.insert(x); // Gather frequencies in a multiset
            }
        }
        for(char c: word2) {
            if(f1[c-'a']==0) {
                return false; // Not a common character in both words
            } else {
                f2[c-'a']++;
            }
        }
        for(int x: f2) {
            if(x!=0) {
                if (s.find(x)==s.end()) {
                    return false; // uncommon freq
                } else {
                    /*
                     * Delete one instance of freq which would
                     * correspond to one of characters (26 options)
                     */
                    s.erase(s.find(x));
                }
            }
        }
        /*
         * if multiset becomes empty, that means there were
         * chars of similar frequencies, otherwise FAIL
         * */
        return s.empty();
    }
};

