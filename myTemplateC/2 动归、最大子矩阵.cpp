#include<iostream>
using namespace std;

#define maxn 105

int MaxSub[maxn];//最大字段和数组
int m[maxn][maxn];//存储原始矩阵
int t[maxn][maxn];//从首行到当前行的和矩阵
int ij[maxn];//从i行到j行所对应的上下值之和
int n;

//最大子序列
int MaxSubSequence(int a[]) {
    int Max=MaxSub[0]=a[0];
    for(int i=1;i<n;i++) {
        MaxSub[i]=(MaxSub[i-1]>0 ? MaxSub[i-1]+a[i]:a[i]);//多次动态规划
        if(MaxSub[i]>Max)//最大值一定在多次动态规划中出现
            Max=MaxSub[i];
    }
    return Max;
}

int MaxSubMatrix() {
    for(int i=1;i<n;i++)
        for(int j=0;j<n;j++)
            t[i][j]+=t[i-1][j];

    int Max=-99999999;
    for(int i=0;i<n;i++)//在这里i、j都是行。类比枚举子串，竖着的子串
        for(int j=i;j<n;j++) {

            for(int f=0;f<n;f++)
                if(i==0) ij[f]=t[j][f];//注意下标，注意j不要写成i，ij为转化之后的序列
                else ij[f]=t[j][f]-t[i-1][f];//注意下标

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
                t[i][j]=m[i][j];//赋初值
            }

        printf("%d\n",MaxSubMatrix());
    }
    return 0;
}
/*
https://www.cnblogs.com/GodA/p/5237061.html
*/
