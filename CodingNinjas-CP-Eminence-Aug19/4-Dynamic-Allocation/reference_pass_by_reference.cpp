#include<bits/stdc++.h>
using namespace std;
/*
 * 1. Bad practice to return a reference variable or a pointer from a function
 * because function's local memory may beflushed after it completes
 *
 * 2. int j& = i; ==> i and j are two variables pointing to a same memory location
 */


int f1(int& x) {

}

int& f2(int x) {

}

int* f3() {
    int i = 10;
    // return &i;
}

int main() {
    int i = 10;
    int& j = i;
    i++;
    cout << j << endl;
    j++;
    cout << i << endl;
    return 0;
}
