#include <iostream>
#include <stdio.h>
#include <string.h>
#define CHARS 260
using namespace std;
 
int main() {
    int T, N, arr[CHARS], p, cents;
    char ch;
    scanf("%d\n", &T);
    while(T--) {
    	scanf("%d\n", &N);
        memset(arr, 0, sizeof arr);
        while (N--){
        	scanf("%c %d\n", &ch, &p);
        	arr[ch + 128] = p;
        } 
        scanf("%d\n", &N);
        cents=0;
        while (N--){
        	while ((ch = getchar()) != '\n') {
                cents += arr[ch + 128];
        	}
        } 
        printf("%d.%02d$\n", cents / 100, cents % 100);
    }
    return 0;
}