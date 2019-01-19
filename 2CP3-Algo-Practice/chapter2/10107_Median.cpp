#include <bits/stdc++.h>
using namespace std; 
 
int main() {
	int n;
	vector<int> v;
    while(scanf("%d", &n) == 1) {
        v.push_back(n);
        for(int i = 0; i < v.size(); i++)
            if(v[i] > n) swap(v[i], v[v.size() - 1]);
        if(v.size() % 2 == 0) {
            printf("%d\n", (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2);
        } else printf("%d\n", v[v.size() / 2]);
    }
}