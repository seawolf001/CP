
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int friendships=0, a=0, b=0, c=0; unordered_map<int, int> umap;
        for(auto& age:ages) umap[age]++;
        for(auto x:umap) {
            for(auto y:umap) {
                a = x.first, b = y.first; c = 0.5*a+7;
                if(b<=c||b>a||(b>100 && a<100)) continue;
                if(a==b) friendships += (x.second) * (y.second-1);
                else friendships += (x.second) * (y.second);
            }
        }
        return friendships;
    }
};

