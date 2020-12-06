/* Jitendra Kumar */
// https://leetcode.com/problems/fibonacci-number/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
private:
    typedef unordered_map<int,int> umap;
    int fib_recursion(int N) {
        // O(2^n) Time | O(n) Space
        if(N==0) return 0;
        if(N==1 || N==2) return 1;
        return fib(N-1)+fib(N-2);
    }
    int fib_memoization(int N, umap &memoize) {
        // O(n) Time | O(n) Space
        if(memoize.count(N)!=0) return memoize[N];
        memoize[N] = fib_memoization(N-1, memoize) + fib_memoization(N-2, memoize);
        return memoize[N];
    }
    int fib_iterative(int N) {
        // O(n) Time | O(1) Space
        // Bottom Up
        if(N==0) return 0;
        if(N==1 || N==2) return 1;
        int x=1, y=1, z=3, s=0;
        while (z <= N) {
            s = x+y;
            x = y;
            y = s;
            z++;
        }
        return y;
    }
public:
    int fib(int N){
        // return fib_recursion(N);
        //umap memoize{{0,0}, {1,1}, {2,1}};
        //return fib_memoization(N, memoize);
        return fib_iterative(N);
    }
};


