#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
private:
    const vector<vector<int>> moves{{0,1},{1,0},{0,-1},{-1,0}}; // up, right, down, left
    bool stop(unordered_set<string> &hs, int x, int y) {
        return hs.find(to_string(x)+"$"+to_string(y)) != hs.end();
    }
    unordered_set<string> hash_obstacles(vector<vector<int>>& obstacles) {
        unordered_set<string> hs;
        for(auto o:obstacles)
            hs.insert(to_string(o[0])+"$"+to_string(o[1]));
        return hs;
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0,y=0,maxd=0;
        int d=0; // 0 --> UP, 1 --> Right, 2 --> Down, 3 --> Left
        unordered_set<string> hs=hash_obstacles(obstacles);
        for(int &cmd:commands) {
            if(cmd==-2) {
                d = (d+3) % 4; // 90 degree left
            } else if(cmd==-1) {
                d = (d+1) % 4; // 90 degree right
            } else {
                int steps=0;
                while((steps < cmd) && !stop(hs, x+moves[d][0], y+moves[d][1])) {
                    x += moves[d][0];
                    y += moves[d][1];
                    ++steps;
                }
                maxd = max(x*x+y*y, maxd);
            }
        }
        return maxd;
    }
};


