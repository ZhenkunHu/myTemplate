#include<bits/stdc++.h>
using namespace std;
int main() {
    const int Mod=1000000;
    int n,s=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int factorial=1;
        for(int j=1;j<=i;j++)
            factorial=factorial*j%Mod;
        s=(s+factorial)%Mod;
    }
    printf("%d\n",s);
    printf("Time used=%.2f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
/*
输入n，计算s=1！+2！+3！+...+n!(不含前导0）。n<=10e6。
*/
//只含加减乘的整数表达式除以正整数n的余数，可以在每步计算之后对n取余，结果不变。
