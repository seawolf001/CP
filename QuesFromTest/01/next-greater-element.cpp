/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

void nextGreaterElement(int * arr, int numberOfElements) {
    stack<int> Stack;
    if(numberOfElements < 1) {
        cout << "Number of elements needs to be greater that 0" << endl;
        return;
    }
    Stack.push(arr[0]);
    for (int i=1; i<numberOfElements; i++) {
        if (Stack.empty() == true) {
            Stack.push(arr[i]);
            continue;
        }
        /*
         * Print all the elements whose nextGreaterElement is arr[i]
         * and pop them out of the stack since they have now been processed.
         */
        while(Stack.empty() != true && Stack.top() < arr[i]) {
            cout << Stack.top() << " --> " << arr[i] << endl;
            Stack.pop();
        }
        /*
         * Push arr[i] to the stack so that we can print nextGreaterElement for arr[i]
         * while we process elements from arr[i+1] to arr[numberOfElements-1].
         */
        Stack.push(arr[i]);
    }
    /*
     * Stack is not empty if there were some elements pushed
     * whose nextGreaterElement element was not found. Otherwise they would have been popped out at some stage.
     */
    while(Stack.empty() == false) {
        cout << Stack.top() << " --> -1" << endl;
        Stack.pop();
    }
}

int main() {
    cout << "Please provide the input in the following format.\n\nN (Number of elments in array)\nN integer values of the array elements\n\n";

    int numberOfElements;
    cin >> numberOfElements;
    int * arr = new int[numberOfElements];
    /*
     * Input the array elements.
     */
    for (int i=0; i<numberOfElements; i++) {
        cin >> arr[i];
    }
    nextGreaterElement(arr, numberOfElements);
    delete[] arr;
    return 0;
}


