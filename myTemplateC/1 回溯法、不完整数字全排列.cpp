#include <stdio.h>
#include <iostream>
using namespace std;

int num[10];
int book[10];
int n=3;

int ans;

void dfs(int x) {
    if(x==n) {
        for(int i=0;i<n;i++)
            printf("%d",num[i]);
        printf("\n");

        ans++;
        return;//当边界写在前面时，可以用return。本题也可以不在这写，会用到最后的return，但本题是巧合
    }

    for(int i=0;i<10;i++) {
        if(book[i]==0) {
            num[x]=i;
            book[i]=1;
            dfs(x+1);
            book[i]=0;
        }
    }
    //return;
}

int main() {

    dfs(0);
    printf("ans:%d\n",ans);

	return 0;
}
/*

*/
