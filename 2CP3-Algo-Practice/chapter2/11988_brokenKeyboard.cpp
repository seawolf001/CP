#include<bits/stdc++.h>
using namespace std;
char s[100010];
int size=0;

int main(){
	while(scanf("%s", s)!=EOF){
		list<char> text;
		list<char>::iterator it = text.begin();
		size = strlen(s);
		for(int i=0;i<size;i++){
			if(s[i]=='[') it = text.begin();
			else if(s[i]==']') it = text.end();
			else text.insert(it, s[i]);
		}
		for(it=text.begin(); it!=text.end(); it++) 
			cout << *it;
		cout << "\n";
	}
}