
/* #include<bits/stdc++.h> */
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
private:
    bool is_subsequence(string w, string s) {
        int i=0;
        for(char c:s) {
            if(w[i]==c) i++;
        }
        return i==w.size();
    }
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int count=0;
        for(string& s:words) {
            if(is_subsequence(s,S)) {
                count++;
            }
        }
        return count;
    }
};
