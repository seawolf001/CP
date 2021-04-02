#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

vector<int> Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    priority_queue<int, vector<int>, greater<int>> q;
    for(int e:A) {
        q.push(e);
        if(q.size() > B)
            q.pop();
    }
    vector<int> ans;
    while(!q.empty()) {
        ans.push_back(q.top());
        q.pop();
    }
    return ans;
}


