/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;


/* Function Templates Example */
template <typename T>
T gcd(T x, T y) {
    if (x==0) return y;
    return gcd(y % x, x);
}

template <typename T>
bool compare(T x, T y) {
    return (x < y);
}

/* Class Templates */
template <typename T, typename U = char>
class Node {
    private:
        T member1;
        U member2;
    public:
        Node() {
            cout << "Constructor without params called." << endl;
        }
        Node(T x, U y) {
            member1 = x;
            member2 = y;
            cout << "Constructor with params called" << endl;
        }
        void printMembers() {
            cout << "member1 = " << member1 << ", member2 = " << member2 << endl;
        }
};

int main() {
    cout << gcd<int>(6,20) << endl;

    cout << compare<int>(1, 2) << endl;
    cout << compare<int>(2, 1) << endl;
    cout << compare<char>('a', 'b') << endl;
    cout << compare<char>('b', 'a') << endl;

    cout << endl;

    Node<int> n1;
    n1.printMembers();

    cout << endl;

    Node<string> n2("Jitendra", 'K');
    n2.printMembers();
    return 0;
}
