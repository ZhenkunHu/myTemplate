#include<iostream>
using namespace std;

#define maxn 105

int MaxSub[maxn];//����ֶκ�����
int m[maxn][maxn];//�洢ԭʼ����
int t[maxn][maxn];//�����е���ǰ�еĺ;���
int ij[maxn];//��i�е�j������Ӧ������ֵ֮��
int n;

//���������
int MaxSubSequence(int a[]) {
    int Max=MaxSub[0]=a[0];
    for(int i=1;i<n;i++) {
        MaxSub[i]=(MaxSub[i-1]>0 ? MaxSub[i-1]+a[i]:a[i]);//��ζ�̬�滮
        if(MaxSub[i]>Max)//���ֵһ���ڶ�ζ�̬�滮�г���
            Max=MaxSub[i];
    }
    return Max;
}

int MaxSubMatrix() {
    for(int i=1;i<n;i++)
        for(int j=0;j<n;j++)
            t[i][j]+=t[i-1][j];

    int Max=-99999999;
    for(int i=0;i<n;i++)//������i��j�����С����ö���Ӵ������ŵ��Ӵ�
        for(int j=i;j<n;j++) {

            for(int f=0;f<n;f++)
                if(i==0) ij[f]=t[j][f];//ע���±꣬ע��j��Ҫд��i��ijΪת��֮�������
                else ij[f]=t[j][f]-t[i-1][f];//ע���±�

            int ans=MaxSubSequence(ij);
            if(ans>Max) Max=ans;
        }
    return Max;
}

int main() {
    while(scanf("%d",&n)==1) {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) {
                scanf("%d",&m[i][j]);
                t[i][j]=m[i][j];//����ֵ
            }

        printf("%d\n",MaxSubMatrix());
    }
    return 0;
}
/*
https://www.cnblogs.com/GodA/p/5237061.html
*/
