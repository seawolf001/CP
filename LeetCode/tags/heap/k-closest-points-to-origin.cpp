#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007

class Solution {
private:
    typedef vector<int> vi;
    typedef vector<vector<int>> vii;
    typedef pair<int, int> pii;
    struct Point {  int x=0, y=0, d=0; };
    struct PointsComparator{
        bool operator() (const Point &p1, const Point &p2) {
            return p1.d <= p2.d;
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<Point, vector<Point>, PointsComparator> minh;
        for(auto &p: points) {
            Point point {p[0], p[1], (p[0]*p[0]+p[1]*p[1])};
            minh.push(point);
            if(minh.size()>K) minh.pop();
        }
        vii closest;
        while(!minh.empty()) {
            auto p = minh.top(); minh.pop();
            closest.push_back({p.x, p.y});
        }
        return closest;
    }
};


