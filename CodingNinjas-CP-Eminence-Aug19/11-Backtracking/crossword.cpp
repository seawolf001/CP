/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;
typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;
typedef std::vector<string> vs;
vs split(const string& s, char delimiter);

vs checkVertical(int x, int y, vs arr, string curr) {
    for(int i=0; i< curr.length(); i++) {
        if(arr[x+i][y] == '-' || arr[x+i][y] == curr[i]) {
            arr[x+i][y] = curr[i];
        } else {
            arr[0][0] = '$';
            return arr;
        }
    }
    return arr;
}

vs checkHorizontal(int x, int y, vs arr, string curr) {
    for(int i=0; i< curr.length(); i++) {
        if(arr[x][y+i] == '-' || arr[x][y+i] == curr[i]) {
            arr[x][y+i] = curr[i];
        } else {
            arr[0][0] = '$';
            return arr;
        }
    }
    return arr;
}

void solveCrossWordPuzzle(vs& words, vs arr, int index, int n) {
    if (index == words.size()){
        for(int i=0;i<n;i++) {
            cout << arr[i] << endl;
        }
        return;
    }
    string curr = words[index];
    int remainLen = n - curr.length();
    for(int i=0;i<n;i++) {
        for(int j=0;j<=remainLen;j++) {
            vs  temp = checkVertical(j, i, arr, curr);
            if(temp[0][0] != '$') {
                solveCrossWordPuzzle(words, temp, index+1, n);
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<=remainLen;j++) {
            vs  temp = checkHorizontal(i, j, arr, curr);
            if(temp[0][0] != '$') {
                solveCrossWordPuzzle(words, temp, index+1, n);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    /* Start writing from here */
    vs arr;
    string s;
    for(int i=0;i<10;i++) {
        getline(cin, s);
        arr.push_back(s);
    }
    getline(cin, s);
    vs words = split(s, ';');
    solveCrossWordPuzzle(words, arr, 0, 10);
    return 0;
}
vs split(const string& s, char delimiter) {
   vs tokens;
   string token;
   stringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter)) {
      tokens.push_back(token);
   }
   return tokens;
}
