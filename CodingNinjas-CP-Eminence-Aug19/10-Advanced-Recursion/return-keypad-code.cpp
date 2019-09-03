/*
 * Author: Jitendra Kumar (seawolf001)
 * Email: jitendra.iitp@gmail.com
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;
typedef std::vector<string> vs;
vector<string> split(const string& s, char delim);

string get_chars(int d) {
    switch(d) {
        case 2: return "abc"; break;
        case 3: return "def"; break;
        case 4: return "ghi"; break;
        case 5: return "jkl"; break;
        case 6: return "mno"; break;
        case 7: return "pqrs"; break;
        case 8: return "tuv"; break;
        case 9: return "wxyz"; break;
        default : return ""; break;
    }
}

void keypad_recurr(int num, string curr, string output[], int& count) {
    if (num <= 0) {
        output[count++] = curr;
        return;
    } else {
        int d = num % 10;
        num /= 10;
        string chars = get_chars(d);
        for (int i=0; i < chars.size(); i++) {
            keypad_recurr(num, chars[i]+curr, output, count);
        }
    }
}

int keypad(int num, string output[]) {
    int count=0;
    keypad_recurr(num, "", output, count);
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    int n=0; cin>>n;
    string output[1000];
    int num = keypad(n, output);
    cout << num << endl;
    for (int i=0;i<num;i++) {
        cout << output[i] << " ";
    }
    cout << endl;
    return 0;
}
vector<string> split(const string& s, char delimiter) {
   vector<string> tokens;
   string token;
   stringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter)) {
      tokens.push_back(token);
   }
   return tokens;
}

