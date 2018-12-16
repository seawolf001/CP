#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int> arr{1,2,3,3,4,8,3,6,5,4,1};
	int n = arr.size();
	cout << "Vector Initially : ";
	for(int i=0; i<n; i++){ cout << arr[i] << " ";} cout << "\n";
	
	//reverse()
	reverse(arr.begin(), arr.end());
	cout << "Vector after reversing  : ";
	for(int i=0; i<n; i++){ cout << arr[i] << " ";} cout << "\n";

	//sort()
	sort(arr.begin(), arr.end());
	cout << "Vector after sorting  : ";
	for(int i=0; i<n; i++){ cout << arr[i] << " ";} cout << "\n";

	// max_element(), min_element(), accumulate()
	cout << "max element in vector : " << *max_element(arr.begin(), arr.end()) << "\n";
	cout << "min element in vector : " << *min_element(arr.begin(), arr.end()) << "\n";
	cout << "Sum of elements in vector : " << accumulate(arr.begin(), arr.end(), 0) << "\n";

	// count(), find()
	cout << "Number of occurance of 3 in vector is : " << count(arr.begin(), arr.end(), 3) << "\n";
	cout << "Search for 20 in vector : ";
	find(arr.begin(), arr.end(), 20) != arr.end() ? cout << "found\n" : cout << "not found\n";

	// binary_search()
	cout << "Binary search in sorted vector : "; 
	binary_search(arr.begin(), arr.end(), 3) == true? cout << "found\n" : cout << "Not found\n";	

	// lower_bound()
	cout << "Lower bound of 4 : ";
	auto position = lower_bound(arr.begin(), arr.end(), 4);
	cout << " was found at index " << position-arr.begin() << " and the element is "<< arr[position-arr.begin()] << "\n";

	// upper_bound()
	cout << "Upper bound of 4 : ";
	auto position_1 = upper_bound(arr.begin(), arr.end(), 4);
	cout << " was found at index " << position_1-arr.begin() << " and the element is "<< arr[position_1-arr.begin()] << "\n";

	/* erase(), Erases and then shif the elements*/
	cout << "Erase value at index 3 : \nBefore : ";
	for(int i=0;i<arr.size();i++) cout << arr[i] << " " ; cout << "\n";	
	arr.erase(arr.begin()+3);
	cout << "After :  ";
	for(int i=0;i<arr.size();i++) cout << arr[i] << " " ; cout << "\n";	

	cout << "Removing duplicate elemenets in vector : ";
	cout << "\nBefore : "; for(int i=0;i<arr.size();i++) cout << arr[i] << " " ; cout << "\n";	
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	cout << "After : "; for(int i=0;i<arr.size();i++) cout << arr[i] << " " ; cout << "\n";	
	return 0;
}