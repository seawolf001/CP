#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> um; int idxsum=INT_MAX; vector<string> ans;
        for(int i=0;i<list1.size();i++) um[list1[i]]=i;
        for(int i=0;i<list2.size();i++){
            if(um.find(list2[i])!=um.end()) {
                int s=i+um[list2[i]];
                if(s<idxsum) {
                    ans.clear(); idxsum=s;
                    ans.push_back(list2[i]);
                } else if(s==idxsum) {
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;
    }
};


