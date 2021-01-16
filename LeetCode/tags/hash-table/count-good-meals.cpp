#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
private:
    unordered_map<int, int> meals;
    long twoPointerSum(int target) {
        auto s=meals.begin(), e=rbegin();
        long count=0;
        while(s!=e) {
            int x = (*s).first, c1=(*s).second, y = (*e).first, c2=(*e).second;
            if(x+y==target) {
                count = (count + (c1*c2) % MOD) % MOD;
            } else if(x+y > target) {
                --e;
            } else {
                s++;
            }
        }
        return count;
    }
public:
    int countPairs(vector<int>& deliciousness) {
        for(int x:deliciousness) items[x]++;
        long counter = 0;
        for(int i=0;i<=21;i++) {
            long target = pow(2,i);
            counter = (counter + goodMeals(target) % MOD) % MOD;
        }
        return counter;
    }
};
