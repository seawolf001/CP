#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class LRUCache {
private:
    int size=0;
    list<int> cache;
    unordered_map<int, pair<int, list<int>::iterator>> mp;
public:
    LRUCache(int capacity) {
        size=capacity;
    }

    int get(int key) {
        auto it=mp.find(key);
        if(it==mp.end())
            return -1;
        cache.erase(mp[key].second);
        cache.push_front(key);
        mp[key].second = cache.begin();
        return mp[key].first;
    }

    void put(int key, int value) {
        if(mp.find(key)==mp.end() && mp.size()==size) {
            // erase last
            int last = cache.back();
            cache.erase(mp[last].second);
            mp.erase(last);
        } else if(mp.find(key)!=mp.end()) {
            // erase and push in front
            cache.erase(mp[key].second);
            mp.erase(key);
        }
        cache.push_front(key);
        mp[key] = make_pair(value, cache.begin());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


