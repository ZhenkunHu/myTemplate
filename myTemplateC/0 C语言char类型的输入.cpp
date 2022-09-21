#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char c[100];
    scanf("%d",&n);

    getchar();//getchar()和scanf("%c",c)都会输入空格和换行
    for(int i=0;i<n;i++)
       scanf("%c",&c[i]);

    printf("%s\n",c);

    return 0;
}
