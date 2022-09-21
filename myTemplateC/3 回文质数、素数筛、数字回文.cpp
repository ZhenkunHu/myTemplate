#include<bits/stdc++.h>
using namespace std;

bool pd_h(int x) {
    //判断数字是否为回文
    int y=x,num=0;//int y=x,防止x被改变
    while (y!=0) {
        num=num*10+y%10;//上一次数字的记录进位再加上下一位数
        y/=10;
    }
    if (num==x) return 1;
    else return 0;
}

const int MAXN = 10000000;
int prime[MAXN];
void Prime() {
    //素数筛
    for (int i=0; i<MAXN; i++) prime[i]=1;  //先把每个数都定义为素数
    prime[0]=prime[1]=0;
    for (int i=2; i<MAXN; i++) {
        if (!prime[i]) continue;
        for (int j=i*2; j<MAXN; j+=i) prime[j] = 0;  //将i的倍数标记为合数
    }
}

int main() {
    Prime();
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=a;i<=b&&i<MAXN;i++) {
        if(pd_h(i)&&prime[i]) printf("%d\n",i);
    }
    return 0;
}
/*
P1217 [USACO1.5]回文质数 Prime Palindromes
1.偶数位数回文数（除11）必定不是质数（自行百度），所以只要运行到10000000。
2.偶数肯定不是质数。
这样至少排除一半多的数据量。3，你回文数已经判断出来了，在此中判断即可。
*/
