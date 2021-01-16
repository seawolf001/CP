#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int> > minh;
    int n=0;
public:
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for(int &x:nums) {
            minh.push(x);
            if(minh.size()>n) minh.pop();
        }
    }
    int add(int val) {
        minh.push(val);
        if(minh.size()>n) minh.pop();
        return minh.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */


