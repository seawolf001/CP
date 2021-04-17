#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

class Solution {
private:
    bool is_valid_ipv4(string s) {
        string curr = "";
        int n = s.size();
        if(n == 0 || s[0] == '.' || s[n-1] == '.')
            return false;
        int segments = 0;
        for(int i=0;i<n;i++) {
            char c = s[i];
            if((c != '.') && (c < 48 || c > 57))
                return false;
            else if(c != '.')
                curr += c;
            if(curr.size() > 3)
                return false;
            if(c == '.' || i == n-1) {
                // we have one segment
                if(curr.size() == 0 || (curr[0] == '0' && curr.size() > 1))
                    return false;
                int val = stoll(curr);
                if(val < 0 || val > 255)
                    return false;
                curr = "";
                ++segments;
            }
        }
        return segments == 4 ?  true: false;
    }
    bool is_valid_ipv6(string s) {
        int n = s.size();
        if(n==0 || s[0]==':' || s[n-1]==':')
            return false;
        string curr = "";
        int segments = 0;
        for (int i=0;i<n;i++) {
            char c = s[i];
            if((c != ':') && !((c>=65 && c<=70) || (c>=97 && c<=102) || (c>=48 && c<=57)))
                return false;
            else if(c != ':')
                curr += c;
            if (curr.size() > 4)
                return false;
            if(c == ':' || i==n-1) {
                if(curr.size() == 0 || curr.size() > 4)
                    return false;
                curr = "";
                ++segments;
            }
        }
        return segments == 8 ? true: false;
    }
public:
    string validIPAddress(string IP) {
        if(is_valid_ipv4(IP))
            return "IPv4";
        else if(is_valid_ipv6(IP))
            return "IPv6";
        return "Neither";
    }
};
