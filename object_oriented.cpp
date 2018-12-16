#include<iostream>
#include<string>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;
class Circle{
private:
	double radius;
	string color;
public:
	string name;
	string fav;
	Circle(double r=1.0, string clr="Red", string name = ""){
		radius = r;
		color = clr;
	}
	double getRadius() const {
		return radius;
	}
	string getColor() const {
		return color;
	}
	double getArea() const{
		return M_PI*radius*radius;
	}
	void setRadius(double r){
		this->radius = r;
	}
	void setName(string name, string fav = "fav"){
		this->name = name;
		this->fav = fav;
	}
};
int main(){
	Circle c1 = Circle(2, "Blue");
	cout << c1.getRadius() << endl;
	cout << c1.getColor() << endl;
	cout << c1.getArea() << endl;
	c1.setRadius(4);
	cout << c1.getRadius() << endl;
	c1.setName("Jitendra");
	cout << c1.name << endl;
	cout << c1.fav << endl;
}
