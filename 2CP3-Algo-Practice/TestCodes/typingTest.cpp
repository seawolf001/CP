#include<algorithm>
#include<cmath>
#include<cstdio>
#include <cstring>
using namespace std;
int N, target;
double dist[200][200], memo[1<<16];
double matching(int bitmask){
	if(memo[bitmask]>-0.5){
		return memo[bitmask];
	} 
	if(bitmask == target){
		return memo[bitmask]=0;
	}
	// to be continued
}

int main(){
	
	return 0;
}