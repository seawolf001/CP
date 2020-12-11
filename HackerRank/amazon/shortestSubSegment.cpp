#include <cmath>
#include <cstdio>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;
#define err "NO SUBSEGMENT FOUND\n"

void solve(vector<string> stmt, vector<string> words, vector<string> original){
    int ns = stmt.size();
    int nw = words.size();
    if(nw>ns) {
        cout << err ;
        return;
    }
    map<string, int> mw;
    map<string, int> ms;
    for(int i=0;i<nw;i++) mw[words[i]]++;
    
    int c=0,s=0,_min=INT_MAX;
    string x="";
    int si=-1;
    
    for(int i=0;i<ns;i++){
        x = stmt[i];
        // cout << "x=" << x << "\n";
        ms[x]++;
        // cout << "ms["<<x<<"]=" << ms[x] << " mw["<<x<<"]=" << mw[x] << "\n";
        if(mw[x] !=0 && ms[x]<=mw[x]) c++;
        if(c==nw){
            while((ms[stmt[s]] > mw[stmt[s]] || mw[stmt[s]] == 0)){
                // cout << "s="<<s<<" stmt[s]=" << stmt[s] << "\n";
                if(ms[stmt[s]] > mw[stmt[s]]) 
                    ms[stmt[s]]--;
                s++;
            }
            int l = i-s+1;
            // cout << "x=" << x << " i="<< i <<" l=" << l << " s=" << s << " _min=" << _min << "\n";
            if(_min > l){
                si=s;
                _min = l;
            }
        }
    }
    if(si==-1){
        cout << err;
        return;
    } else {
        for(int i=si; i<si+_min;i++){
            cout << original[i] << " ";
        }
        cout << "\n";
        return;
    }
}
vector<string> split(string s){
    stringstream ss(s);
    string word1="", word2="";
    vector<string> v;
    while(ss>>word1){
        word2 = "";
        for(int i=0; word1[i] ;i++){
            if(isalpha(word1[i])) word2 += word1[i];
        }
        // cout << "\nword2="<< word2 << " ";
        v.push_back((word2));
    }
    return v;
} 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    string str="",s="";
    
    getline(cin, str);
    vector<string> original = split(str);
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    vector<string> stn = split(str);
    
    int k=0; cin>>k;
    vector<string> words; 
    for(int i=0;i<k;i++){
        cin>>s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        words.push_back(s);
    } 
    solve(stn, words, original);
    return 0;
}