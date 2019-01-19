#include<bits/stdc++.h>
#define CHARS 256
#define M 34
#define endl "\n"
using namespace std;

string s1="";
string s2="";
int n=0;
int num=0;
int _next=0;
bool first=false;

bool anagrams(string a, string b){
	int arr[CHARS];
	for(int i=0;i<CHARS;i++) arr[i]=0;
	if(a.length()!=b.length()) return false;
	for(int i=0;i<a.length();i++){
		arr[a[i]]++;
		arr[b[i]]--;
	}
	for(int i=0;i<CHARS;i++){
		if(arr[i]!=0) return false;
	}
	return true;
}
void dfs(string s, stack<char> st, string curr, int push, int pop, string _bitset, vector<string> &v){
	if(pop > push) return;
	if(curr.length()==n){
		if(curr==s2){
			string out="";
			for(int i=0; i< 2*n;i++){
				if(_bitset[i]=='i' && first==true){
					first=false;
					out+="i";
				} else if(_bitset[i]=='i' && first==false) {
					out+=" i";
				} else {
					out+=" o";
				}
			}
			v.push_back(out);
			return ;
		}
	}
	if(_bitset[_next++]=='i'){
		if(s.length()>0){
			char c = s[0];
			push++;
			st.push(c);
			if(push <= n) dfs(s.substr(1, s.size()-1), st, curr, push, pop, _bitset, v);
			else return;
		}
	} else {
		if(st.empty()) return;
		char c = st.top();
		if(c != s2[curr.length()]) return;
		st.pop();
		pop++;
		if(pop <= n) dfs(s, st, curr+c, push, pop, _bitset, v);	
		else return ;
	}
}
bool valid(string pattern){
	int push=0;
	int pop=0;
	for(int i=0;i<pattern.length();i++){
		if(pattern[i]=='o') pop++;
		else if(pattern[i]=='i') push++;
	}
	return (push== n && pop==n);
}
int main(){
	while(cin>>s1>>s2){
		cout << "[\n";
		if(anagrams(s1, s2)){
			vector<string> v;
			n=s1.length();
			num = pow(2, 2*n)-1;
			for(int i=0;i<=num;i++){
				bitset<M> Bitset(i);
				int ones = Bitset.count();
				string _bitset = Bitset.to_string('o', 'i');
				reverse(_bitset.begin(), _bitset.end());
				_bitset = _bitset.substr(0, 2*n);
				reverse(_bitset.begin(), _bitset.end());
				if(valid(_bitset)){
					if(_bitset[0] != 'o'){
						first =  true;
						_next=0;
						stack<char> st;
						int push=0; int pop=0;
						string curr = "";
						dfs(s1, st, curr, push, pop, _bitset, v);
					}
				}
			}
			sort(v.begin(), v.end());
			for(auto x : v) cout << x << endl;
			v.clear();
		}
		cout << "]\n";
	}
	return 0;
}