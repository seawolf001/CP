#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

int ballons(vector<int> arr, int n) {
    unordered_map<int, int> ump;
    int arrows = 0;
    for(int &x: arr) {
        if (ump[x+1] ==  0) {
            ++arrows;
        }
        ump[x]++;
    }
    return arrows;
}

int main() {
    int n = 0; cin >> n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cout << ballons(arr, n) << endl;
}
