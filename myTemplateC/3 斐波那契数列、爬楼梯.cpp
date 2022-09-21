#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1) {
        long long a[95];
        a[0]=0;
        a[1]=1;
        for(int i=2;i<=n;i++)
            a[i]=a[i-1]+a[i-2];//斐波那契数列
        printf("%lld\n",a[n]);
    }
    return 0;
}

/*
从数学角度来理解1 2 3 5，如果不能从算法角度来理解的话
*/
