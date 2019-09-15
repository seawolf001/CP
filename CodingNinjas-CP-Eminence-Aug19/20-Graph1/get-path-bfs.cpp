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

void bfs(vi arr[], int n, int x, int y) {
    bool * vis=new bool[n];
    memset(vis, false, n*sizeof(bool));
    queue<int> q;
    q.push(x);
    vis[x]=true;
    unordered_map<int, int> m;
    m[x]=INT_MAX;
    bool found=false;
    while(!q.empty()) {
        int front=q.front();
        q.pop();
        if(front == y) {
            found=true;
            break;
        }
        for(auto it=arr[front].begin(); it!=arr[front].end(); it++) {
            if(!vis[*it]) {
                vis[*it]=true;
                m[*it]=front;
                q.push(*it);
            }
        }
    }
    if(found) {
        int curr=y;
        while(curr!=INT_MAX){
            cout << curr << " ";
            curr=m[curr];
        }
    } else {
        cout << "" << endl;
    }
    delete[] vis;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n,e,x,y;
    cin>>n>>e;
    vi arr[n];
    for (int i=0;i<e;i++) {
        cin>>x>>y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    cin>>x>>y;
    bfs(arr, n, x, y);
    return 0;
}


