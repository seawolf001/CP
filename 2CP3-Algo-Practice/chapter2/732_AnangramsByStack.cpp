#include<bits/stdc++.h>
#define CHARS 260
#define endl "\n"
using namespace std;
char s1[105], s2[105], st[105], p[105];
int n=0, m=0;

void dfs(int i, int push, int pop){
	if(push == n && pop == n){
		for(int j=0;j<i;j++){
			if(j!=0) putchar(' ');
			putchar(p[j]);
		}
		printf("\n");
		return ;
	}
	if(push < n){
		st[m++]=s1[push];
		p[i]='i';
		dfs(i+1, push+1, pop);
		m--;
	} 
	if(push > pop){
		if(st[m-1]==s2[pop]){
			p[i]='o';
			m--;
			dfs(i+1,push,pop+1);
			m++;
			st[m-1]=s2[pop];
		}
	}
}
int main(int argc, char const *argv[])
{
	while(scanf("%s",s1)==1){
		getchar();
		scanf("%s",s2);
		getchar();

		printf("%s\n","[");
		n=strlen(s1); 
		m=0;
		if(strlen(s2)==n){
			int i=0; int push=0; int pop=0;
			dfs(i, push, pop);
		}
		printf("%s\n","]");
	}	
	return 0;
}