#include<bits/stdc++.h>
using namespace std;

bool pd_h(int x) {
    //�ж������Ƿ�Ϊ����
    int y=x,num=0;//int y=x,��ֹx���ı�
    while (y!=0) {
        num=num*10+y%10;//��һ�����ֵļ�¼��λ�ټ�����һλ��
        y/=10;
    }
    if (num==x) return 1;
    else return 0;
}

const int MAXN = 10000000;
int prime[MAXN];
void Prime() {
    //����ɸ
    for (int i=0; i<MAXN; i++) prime[i]=1;  //�Ȱ�ÿ����������Ϊ����
    prime[0]=prime[1]=0;
    for (int i=2; i<MAXN; i++) {
        if (!prime[i]) continue;
        for (int j=i*2; j<MAXN; j+=i) prime[j] = 0;  //��i�ı������Ϊ����
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
P1217 [USACO1.5]�������� Prime Palindromes
1.ż��λ������������11���ض��������������аٶȣ�������ֻҪ���е�10000000��
2.ż���϶�����������
���������ų�һ������������3����������Ѿ��жϳ����ˣ��ڴ����жϼ��ɡ�
*/
