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
            a[i]=a[i-1]+a[i-2];//쳲���������
        printf("%lld\n",a[n]);
    }
    return 0;
}

/*
����ѧ�Ƕ������1 2 3 5��������ܴ��㷨�Ƕ������Ļ�
*/
