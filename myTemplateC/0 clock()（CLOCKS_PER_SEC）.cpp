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
����n������s=1��+2��+3��+...+n!(����ǰ��0����n<=10e6��
*/
//ֻ���Ӽ��˵��������ʽ����������n��������������ÿ������֮���nȡ�࣬������䡣
