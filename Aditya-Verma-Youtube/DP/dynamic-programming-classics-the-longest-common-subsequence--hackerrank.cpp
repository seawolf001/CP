/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the longestCommonSubsequence function below.
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    int m = a.size();
    int n = b.size();
    if(m==0 || n==0) return 0;
    int dp[m+1][n+1]; vis[m+1][n+1];
    for(int i=0;i<=m;i++) {
        for(int j=0;j<=n;j++) {
            if(i==0 || j==0) dp[i][j]=0;
            else if(a[i-1]==a[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                vis[i][j]=true;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }

        }
    }
    int l=dp[m][n];
    vector<int> ans;
    bool exit=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(vis[i][j]) {
                ans.push_back(a[i-1]);
                l--;
                if(l==0) {
                    exit=1;
                    break;
                }
            }
        }
        if(exit) break;
    }
    return reverse(ans.begin(); ans.end());
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split_string(b_temp_temp);

    vector<int> b(m);

    for (int i = 0; i < m; i++) {
        int b_item = stoi(b_temp[i]);

        b[i] = b_item;
    }

    vector<int> result = longestCommonSubsequence(a, b);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

