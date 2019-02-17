#include<bits/stdc++.h>
using namespace std;
#define N 1000001
#define bits 23
#define ll long long
int dp[N][bits];

bool check(int n, int k){
    if(n & (1<<(k-1))) return true;
    return false;
}

void pre_process(){
    for(int i=0;i<bits; i++) {
        dp[0][i]=0;
    }
    bool f=false;
    for(int i=0;i<N;i++){
        for(int j=1;j< bits;j++){
            if(i) 
                dp[i][j] = dp[i-1][j];
            f = check(i, j);
            if(f) 
                dp[i][j]++;
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<4;j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}

vector<int> solve (vector<vector<int> > queries, int q,int s) {
   // queries is a q*s matrix containing the query values
   // Write your code here
   vector<int> res;
   for(int i=0;i<queries.size();i++){
       int L = queries[i][0]-1;
       int R = queries[i][1]-1;
       int K = queries[i][2];
       if(L){
           res.push_back(dp[R][K]-dp[L-1][K]);
       } else {
           res.push_back(dp[R][K]);
       }
   }
   return res;
}

int main() {
    memset(dp, 0, sizeof dp);
    pre_process();/*
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int s;
    cin >> s;
    vector<vector<int> > queries(n, vector<int>(s));
    for (int i_queries=0; i_queries<n; i_queries++)
    {
      for(int j_queries=0; j_queries<s; j_queries++)
      {
        cin >> queries[i_queries][j_queries];
      }
    }

    vector<int> out_;
    out_ = solve(queries,n,s);
    cout << out_[0];
    for(int i_out_=1; i_out_<out_.size(); i_out_++)
    {
      cout << " " << out_[i_out_];
    }*/
}