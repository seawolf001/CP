
#include<bits/stdc++.h>
using namespace std;

/*
 Minimum subarray having K beautiful numbers
 Beautiful number: have odd number of divisors
 * */

void cache_perfect_squares(vector<long long> arr, int N, unordered_map<int, bool> &cache) {
    for(int i=0;i<N;i++) {
        double sq = sqrt(arr[i]);
        if((long long)sq == sq) cache[i]=true;
    }
}

int Solve (int N, vector<long long> A, int K) {
   // Write your code here
    unordered_map<int, bool> cache;
    cache_perfect_squares(A, N, cache);
    int s=0, e=0, count=0, ans=INT_MAX;
    while(e<N) {
        count += cache[e++] ? 1 : 0;
        while(s<=e && count > K) {
            if(cache[s]) --count;
            ++s;
        }
        if(count==K) ans = min(ans, e-s);
        // cout << s << " " << e << endl;
    }
    return ans==INT_MAX ? -1 : ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        vector<long long> A(N);
        for(int i_A = 0; i_A < N; i_A++)
        {
        	cin >> A[i_A];
        }
        int K;
        cin >> K;

        int out_;
        out_ = Solve(N, A, K);
        cout << out_;
        cout << "\n";
    }
}
