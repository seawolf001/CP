#include<iostream>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>

using namespace std;
int main(int argc, char const *argv[])
{
	char str[] = "I am Jitendra";
	char *token;
	token = strtok(str, " ");
	while(token != NULL){
		cout << "current token : " << token << endl;
		token = strtok(NULL, " ");
	}

	/*  using strings as character array*/
	char s1[] = "Hello This is Jitendra, Hello This is Jitendra";
	cout << strlen(s1) << endl;
	char s2[strlen(s1)];
	strcpy(s2, s1);
	cout << "This is s2: " << s2 << endl;
	char *p = s1; int total=0;
	while((p = strstr(p, "Hello")) != NULL){
		cout << "Location : " << p << endl;
		p += strlen("Hello");
		total++;
	} 
	cout << "Total number of occurances : " <<total << endl;
	char src[] ="Hello";
	char dest[25] = "";
	int a  = strlen(src);
	cout << strlen(src)<<endl;
	strncat(dest, src, a);
	cout << dest << " " << strlen(src) << endl;

	string s = "abcd";
	for(int i=0; i< s.length(); i++){
		for(int len = 1; len<= s.length()-i; len++){
			cout << s.substr(i, len) << endl;
		}
	}
	
	return 0;
}