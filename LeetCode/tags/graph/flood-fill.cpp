#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
private:
    bool valid(vii &image, int x, int y, int o, int n, int m) {
        if(x<0||x>=n||y<0||y>=m) return false;
        return image[x][y]==o;
    }
    void dfs(vii &image, int x, int y, int o, int c, int n, int m) {
        if(!valid(image,x,y,o,n,m)) return;
        image[x][y]=c;
        dfs(image,x+1,y,o,c,n,m);
        dfs(image,x,y+1,o,c,n,m);
        dfs(image,x-1,y,o,c,n,m);
        dfs(image,x,y-1,o,c,n,m);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(), m = n>0 ? image[0].size() : 0;
        if(image[sr][sc]==newColor) return image;
        dfs(image, sr, sc, image[sr][sc], newColor, n, m);
        return image;
    }
};

