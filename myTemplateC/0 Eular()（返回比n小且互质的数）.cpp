#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
int P,N,K;
vector<int> fac[maxn];
int facnum[maxn];
int sum[maxn];
void findfac(int n)//寻找n的质数吗
{
    fac[n].push_back(1);
    for(int i=2;i<sqrt(n)+1;i++)
    {
        if((n%i)==0)
        {
            fac[n].push_back(i);
            if(n/i<i)
            {
                fac[n].push_back(n/i);
            }

        }

    }
}

int eular(int n)
{
    int ret=1;
    for(int i=2;i*i<=n;i++)
    {
        if((n%i)==0)
        {
            n/=i;
            ret*=i-1;
            while(n%i==0)
            {

                n/=i;
                ret*=i;
            }
        }
    }
    if(n>1) ret*=n-1;
    return ret;

}
void init()
{
    memset(facnum,0,sizeof(facnum));
    memset(sum,0,sizeof(sum));
    facnum[1]=2;
    sum[1]=2;
    for(int i=2;i<maxn;i++)
    {
        facnum[i]=eular(i);
        sum[i]=sum[i-1]+facnum[i];
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //cout<<eular(2)<<endl;
    init();
    scanf("%d",&P);
    for(int ca=0;ca<P;ca++)
    {
        scanf("%d %d",&K,&N);
        printf("%d %d\n",K,sum[N]);
    }
    //cout<<"aa"<<endl;
}
/*

*/
//预处理计算for any n, 比n小且互质的数的个数。我是翻模板才发现有个Eular函数可以直接算的，难得人品爆发一回。
//因为N的 farey sequence包括了N-1的farey sequence，所以可以利用前缀和，注意N=1要单独处理。
