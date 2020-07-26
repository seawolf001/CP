/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        unordered_set<int> s;
        s.clear();
        int x = int(numerator/denominator);
        int remainder = numerator % denominator;
        if (remainder==0) { return to_string(x); }
        string curr = "";
        while (true) {
            if (s.count(remainder) !=0) break;
            s.insert(remainder);
            remainder *= 10;
            while (remainder < numerator) {
                remainder *= 10;
                curr += "0";
            }
            curr += to_string(remainder/numerator);
            remainder = remainder % numerator;
        }
        return to_string(x) + ".(" + curr + ")";
    }
};
