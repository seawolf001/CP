#include<bits/stdc++.h>
using namespace std;

/*Dynamically allocating memory which will go on HEAP*/

int main() {
    int * p = new int;
    *p = 10;
    cout << *p << endl;

    int * arr = new int[50];

    int n;
    cin >> n;
    int * a1 = new int[n];

    //static allocation
    while (true) {
        int a = 10; // vanishes after scope of while loop, overall we are using only 4bytes
    }

    //Dynamically allocating
    while(true) {
        int a = new int; // a is created in heap and not destroying ==> memory overflow
    }

    /* Always deallocate the Dynamically created memory*/
    delete p; //deletes the memory to which p was pointing
    delete[] a; // deletes the memory to which a was pointing
    return 0;
}
