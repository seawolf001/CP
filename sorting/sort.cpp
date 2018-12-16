#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef std::vector<ll> vll;
typedef std::vector<ld> vld;
typedef std::vector<int> vi;
typedef std::vector<string> vs;
const ll mod=1e9+7;
#define sync ios_base::sync_with_stdio(false);cin.tie(0);
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n;i>=0;i--)
#define forv(it, v) for(auto it=v.begin(); it!=v.end(); it++)
#define endl '\n'
#define mp make_pair
#define pb(x) push_back((x))

vs split(string s, char delimiter){
	vs tokens;
	string token;
	stringstream token_stream(s);
	while(getline(token_stream, token, delimiter)){
		tokens.pb(token);
	}
	return tokens;
}
void heapify(vi arr, int n, int i){
	int max=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && arr[l]>arr[max]) max=l;
	if(r<n && arr[r]>arr[max]) max=r;
	if(max!=i){
		// swap(arr[i], arr[max]);
		int temp = arr[i]; arr[i]=arr[max]; arr[max]=temp;
		heapify(arr,n,max);
	}
}
void heap_sort(vi arr){
	int n = arr.size();
	per(i,n/2-1) heapify(arr, n, i);
	per(i,n-1){
		// swap(arr[0], arr[i]);
		int temp=arr[0];arr[0]=arr[i];arr[i]=temp;
		heapify(arr,i,0);
	}
	rep(i,n) cout<<arr[i]<<" "; cout << endl;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cout << "Enter the elements : ";
	string str;
	getline(cin, str);
	vs p = split(str, ' ');
	vi q;
	rep(i,p.size()) q.pb(stoi(p[i]));
	heap_sort(q);
	return 0;
}