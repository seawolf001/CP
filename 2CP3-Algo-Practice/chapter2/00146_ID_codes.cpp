#include<bits/stdc++.h>
using namespace std;
void swap(char *a, char *b){
	if(*a==*b) return;
	char temp=*a;
	*a=*b;
	*b=temp;
}
int binary_search(string &s, int l, int r, int c){
	int index=-1;
	while(l<=r){
		int mid=l+(r-1)/2;
		if(s[mid]<=c) r = mid-1;
		else {
			l = mid+1;
			if(index = -1 || s[index]<=s[mid]){
				index=mid;
			}
		}
	}
	return index;
}
void reverse(string &s, int l, int r){
	while(l<r) swap(&s[l++], &s[r--]);
}
bool _next_permutation(string &s){
	int r = s.length()-1;
	int i=r-1;
	while(i>=0 && s[i]>=s[i+1]) i--;
	if(i<0) return false;
	int index = binary_search(s, i+1, r, s[i]);
	swap(&s[i], &s[index]);
	reverse(s, i+1, r);
	return true;
}
int main(){
	string s;
	while(cin>>s, s != "#"){
		/*bool done =  next_permutation(s.begin(), s.end()); // inbuilt function*/
		bool done = _next_permutation(s);
		if(done)
			cout << s << "\n";
		else 
			cout << "No Successor" << "\n";
	}
	return 0;
}