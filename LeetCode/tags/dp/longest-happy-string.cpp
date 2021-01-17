#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

// https://leetcode.com/problems/longest-happy-string/discuss/564277/C%2B%2BJava-a-greater-b-greater-c

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string happy="";
        vector<pair<int, char>> chars{{a,'a'}, {b, 'b'}, {c,'c'}};
        sort(chars.begin(), chars.end(), greater<pair<int, char>>()); // sort by frequency
        while(chars[1].first!=0) {
            int c1 = min(2, chars[0].first);
            happy += string(c1, chars[0].second); chars[0].first -= c1;
            int c2 = chars[0].first >= chars[1].first ?  1 : 0;
            happy += string(c2, chars[1].second); chars[1].first -= c2;
            sort(chars.begin(), chars.end(), greater<pair<int, char>>()); // sort by frequency
        }
        int c3 = min(2, chars[0].first); happy += string(c3, chars[0].second);
        return happy;
    }
};



