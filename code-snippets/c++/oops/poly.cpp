#include<bits/stdc++.h>
using namespace std;

class Country {
public:
    virtual string capital() {
        return "CAPITAL";
    }
};

class India: public Country {
public:
    string capital() {
        return "Delhi";
    }
};

class USA: public Country {
public:
    string capital() {
        return "Washington DC";
    }
};

void print_capital(Country * c) {
    cout << c->capital() << endl;
}

int main() {
    Country * c;
    India obj1;

    c = &obj1;

    print_capital(c);

    USA * obj2;
    print_capital(obj2);
}


