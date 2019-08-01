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


int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
    if (size<=0) return 0;
    int count = allIndexes(input+1, size-1, x, output);
    if (input[0] ==x) {
        for(int i=count-1; i>=0; i--) {
            output[i+1] = output[i]+1;
        }
        output[0]=0;
        count++;
    } else {
        for (int i = count - 1; i >= 0; i--) {
            output[i] = output[i] + 1;
        }
    }
    return count;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */

    return 0;
}

