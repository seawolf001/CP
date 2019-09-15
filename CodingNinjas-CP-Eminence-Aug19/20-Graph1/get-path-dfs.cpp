/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;
typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;
typedef std::vector<string> vs;

bool DFS(vi arr[], int n, int x, int y, bool* vis, vi &ans) {
    if(x==y) { return true; }
    vis[x]=true;
    for(auto it=arr[x].begin(); it!=arr[x].end(); it++) {
        if(!vis[*it]) {
            if(DFS(arr, n, *it, y, vis, ans)) {
                ans.push_back(*it);
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n,e,x,y;
    cin>>n>>e;
    vi arr[n];
    for(int i=0;i<e;i++) {
        cin>>x>>y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    cin>>x>>y;
    for (int i=0;i<n;i++) { sort(arr[i].begin(), arr[i].end()); }
    vi ans;
    bool* vis=new bool[n];
    memset(vis, false, n*sizeof(bool));
    if(DFS(arr, n, x, y, vis, ans)) {
        ans.push_back(x);
        for(auto i=ans.begin(); i!=ans.end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    } else {
        cout << "" << endl;
    }
    delete[] vis;
    return 0;
}


