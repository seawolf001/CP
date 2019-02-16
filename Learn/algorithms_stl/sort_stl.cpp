#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define FR(i,n) for(int i=0; i<n; i++)
struct Interval{
	int start;
	int end;
};
bool comparator(Interval a, Interval b){
	/*sorting according to ascendinf order of end values*/
	return (a.end > b.end);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i=0;
	int arr[] = {1,2,7,6,3,4,5,9,8};
	int n = (sizeof arr)/ (sizeof arr[0]);
	/* descending order*/
	sort(arr, arr+n, greater<int>());
	FR(i,n) cout << arr[i] << " "; cout << "\n";
	/* ascending order*/
	sort(arr, arr+n);
	FR(i,n) cout << arr[i] << " "; cout << "\n";

	/* custom comparator for sorting other data structures*/
	Interval interval[] = {{6,8}, {1,9}, {2,4}, {4,7}};
	int size_interval = (sizeof interval)/(sizeof interval[0]);
	sort(interval, interval+size_interval, comparator);
	FR(i,size_interval)
		cout << interval[i].start <<  " " <<interval[i].end << "\n";
	return 0;
}