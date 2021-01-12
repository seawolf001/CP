
#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class RandomizedSet {
private:
    vector<int> v;
    unordered_map<int, int> idx;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        v.clear();
        idx.clear();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(idx.find(val)!=idx.end()) return false;
        v.push_back(val);
        idx[val]=v.size()-1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(idx.find(val)==idx.end()) return false;
        int temp = v[idx[val]];
        idx[v[v.size()-1]] = idx[temp];
        v[idx[val]] = v[v.size()-1];
        v[v.size()-1] = temp;
        idx.erase(temp);
        v.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */




