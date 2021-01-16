#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
private:
    typedef vector<string> vs;
    typedef vector<vector<string>> vvs;
    unordered_map<string, vs> tracker;
public:
    vvs findDuplicate(vs &paths) {
        vvs duplicates; string dir="", file="", content="", tmp="";
        for(string &path:paths) {
            stringstream ss(path); getline(ss, dir, ' ');
            while(getline(ss, tmp, ' ')) {
                int i=0, j=0;
                while(tmp[++j]!='(');
                file = tmp.substr(i,j-i);
                i=++j; while(tmp[++j]!=')');
                content = tmp.substr(i,j-i);
                tracker[content].push_back(dir+"/"+file);
            }
        }
        for(auto &e:tracker) {
            if(e.second.size()>1)
                duplicates.push_back(e.second);
        }
        return duplicates;
    }
};


