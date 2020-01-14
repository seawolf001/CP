/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;

class Animal {
    private:
        string name; // Accessible only within the class;
    protected:
        int age; // Accessible within class and sub-classes;
    public:
        char sex = '\0'; // publically acessible;
        Animal(string x, int n, char c) {
            name = x;
            age = n;
            sex = c;
        }
        string get_name() {
            return name;
        }
        int get_age() {
            return age;
        }
};

class Dog: protected Animal {
    Dog(string x, int n, char c) {
        name = x;
        age =
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* Start writing from here */
    Animal a1("Dog", 10, 'M');
    cout << a1.get_name() << " " << a1.get_age() << " " << a1.sex << endl;
    return 0;
}


