#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vector<int>> vii;

class Solution {
private:
    double area(vi &x,  vi &y, vi &z) {
        double a,b,c,s;
        a = sqrt((x[0]-y[0])*(x[0]-y[0])+(x[1]-y[1])*(x[1]-y[1]));
        b = sqrt((y[0]-z[0])*(y[0]-z[0])+(y[1]-z[1])*(y[1]-z[1]));
        c = sqrt((z[0]-x[0])*(z[0]-x[0])+(z[1]-x[1])*(z[1]-x[1]));
        s = (a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size(); double maxArea=INT_MIN;
        for(int i=0;i<n-2;i++) {
            for(int j=i+1;j<n-1;j++) {
                for(int k=j+1;k<n;k++) {
                    maxArea = max(maxArea, area(points[i], points[j], points[k]));
                }
            }
        }
        return maxArea;
    }
};


