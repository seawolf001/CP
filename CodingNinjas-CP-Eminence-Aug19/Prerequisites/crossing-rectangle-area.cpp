#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;

    int x3,y3,x4,y4;
    cin>>x3>>y3>>x4>>y4;

    int a1 = (x2-x1)*(y2-y1);
    int a2 = (x4-x3)*(y4-y3);

    int l = max(x1,x3);
    int r = min(x2,x4);
    int t = min(y2,y4);
    int b = max(y1,y3);

    int x=0;
    if(l<r && b<t){
        x = (r-l)*(t-b);
    }

    int ans = a1+a2-x;
    cout << ans << endl;
    return 0;
}
