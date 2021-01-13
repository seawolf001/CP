
/* #include<bits/stdc++.h> */
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>> idx(26);
        for(int i=0;i<S.size();i++)  idx[S[i]-'a'].push_back(i);
        int count=0;
        for(string& w:words) {
            int prev=-1; int matched=0;
            for(char& c:w) {
                auto it=upper_bound(idx[c-'a'].begin(), idx[c-'a'].end(), prev);
                if(it==idx[c-'a'].end()) break;
                prev=*it; matched++;
            }
            if(matched==w.size()) count++;
        }
        return count;
    }
};


