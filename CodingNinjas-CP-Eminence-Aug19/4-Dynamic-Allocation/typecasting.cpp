#include<bits/stdc++.h>
using namespace std;

int main() {
    int i = 65;
    char c = i; //implicit typecasting

    int* p = &i;
    // char* pc = p; // throws error
    char* pc = (char*) p; // explicit typecasting

    cout << *p << endl;
    cout << *pc << endl;

    cout << *(pc+1) << endl;
    cout << *(pc+2) << endl;
    cout << *(pc+3) << endl;

    cout << p << endl;  // prints address
    cout << pc << endl; // print content till '\0'
    return 0;
}
