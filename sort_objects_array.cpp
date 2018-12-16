#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Fruits{
	public:
		string name;
		double price;
		Fruits(string s, double p){
			this->name = s;
			this->price = p;
		}
};
bool sort_by_name(Fruits& a, Fruits& b){
	return a.name < b.name;
}
bool sort_by_price(Fruits& a, Fruits& b){
	return a.price < b.price;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string name; 
	double price;
	std::vector<Fruits> arr;
	while(true){
		cin >> name;
		if(name == "exit") break;
		cin >> price;
		arr.push_back(Fruits(name, price));
	}
	sort(arr.begin(), arr.end(), sort_by_name);
	for(int i=0;i<arr.size();i++){
		cout << arr[i].name << " " << arr[i].price << "\n";
	}
	sort(arr.begin(), arr.end(), sort_by_price);
	for(int i=0;i<arr.size();i++){
		cout << arr[i].name << " " << arr[i].price << "\n";
	}
	return 0;
}