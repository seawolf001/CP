/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

/*
1) Use a data structure like map or vector<int>(256) for tracking occurance
2) Use bitset of size 256 for less space. each flag take single bit instead bool taking 8 bits
3) use sorting for no using aditional data structure
*/

string isUnique(string s){
  unordered_map<char, int> tracker;
  int x;
  for (char c: s) {
    x = (int)c;
    if(tracker[x] != 0) return "NO";
    tracker[x]++;
  }
  return "YES";
}

