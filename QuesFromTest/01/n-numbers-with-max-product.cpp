/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

void pick_N_numbers(vector<int> arr, int numberOfElements, int N, vector<int> &pickedNumbers) {
    if(N>numberOfElements) {
        /*
         * Can opt to choose at max int(numberOfElements) of elements.
         */
        cout << "Number of items can not be greater than total number of elements present in array";
        return;
    }
    sort(arr.begin(), arr.end());
    int j = numberOfElements-1;
    if(N & 1) {
        /*
         * Number of elements to be choose is ODD.
         */
        if(arr[numberOfElements-1] <= 0) {
            /*
             * Start selecting from right margin.
             */
            int count=0;
            for(int i= numberOfElements-1; count < N; i--) {
                pickedNumbers.push_back(arr[i]);
                count++;
            }
            return;
        } else {
            /*
             * choose the last and greatest one and decrease the counter.
             * Now since number of elements to be choosen has become EVEN, move ahead with below logic.
             */
            N -= 1;
            pickedNumbers.push_back(arr[j]);
            j--;
        }
    }
    N = N >> 1; /* Will be choosing the elements in pairs. */
    int i = 0, k = 0, left=0, right=0;
    for(k=0; k<N; k++) {
        left = ( arr[i] * arr[i+1] );
        right = ( arr[j] * arr[j-1] );
        if(left > right) {
            /*
             * choose from left margin
             */
            pickedNumbers.push_back(arr[i]);
            pickedNumbers.push_back(arr[i+1]);
            i += 2;
        } else {
            /*
             * choose from right margin.
             */
            pickedNumbers.push_back(arr[j]);
            pickedNumbers.push_back(arr[j-1]);
            j -= 2;
        }
    }
}

int main() {
    cout << "Please provide the input in the following format.\n\nN (Number of elments in array)\nN integer values of the array elements\n\n";
    int numberOfElements = 0, temp=0;
    cin >> numberOfElements;
    vector<int> arr;
    for (int i=0;i<numberOfElements; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    int N = 0;
    cin >> N;
    vector<int> pickedNumbers;
    pick_N_numbers(arr, numberOfElements, N, pickedNumbers);
    vector<int>::iterator it;
    for(it=pickedNumbers.begin(); it!=pickedNumbers.end(); it++) {
        cout << (*it) << " ";
    }
    cout << endl;
    return 0;
}


