#include<bits/stdc++.h>
using namespace std;

const int Max=10010;

/* 枚举子串 知识盲点
for(int i=0;i<n;i++)
{
    for(int j=i;j<n;j++)
    {
        sum = 0;
        for(int k=i;k<=j;k++)
            sum += a[k];
        if(sum > max)    max = sum;
    }
}

注意i与j
for(i=0;i<n;i++)
{
    for(j=0;j<=i;j++)
    {
        sum = 0;
        for(k=j;k<=i;k++)
            sum += a[k];
        if(sum > max)    max = sum;
    }
}
*/

/*
我们来分析一下最优子结构，若想找到n个数的最大子段和，那么要找到n-1个数的最大子段和
我们用b[i]来表示a[0]...a[i]的最大子段和，b[i]无非有两种情况:
(1)最大子段一直连续到a[i] 　(2)以a[i]为首的新的子段

//最大子序列
int MaxSubSequence(int a[]) {
    int Max=MaxSub[0]=a[0];
    for(int i=1;i<n;i++) {
        MaxSub[i]=(MaxSub[i-1]>0 ? MaxSub[i-1]+a[i]:a[i]);//状态转移方程
        if(MaxSub[i]>Max)//最大值一定在多次动态规划中出现
            Max=MaxSub[i];
    }
    return Max;
}
*/

int main() {
    int k;
    while(cin>>k&&k) {
        int a[Max];
        int flag=1;
        for(int i=0;i<k;i++) {
            cin>>a[i];
            if(a[i]>0) flag=0;//如果出现正数，flag=0
        }

        int sum=a[0],left=0,temp,right=0;
        int MAX=0;
        if(flag) cout<<MAX<<" "<<a[0]<<" "<<a[k-1]<<endl;
        else {
            MAX=a[0];
            left=right=0;
            for(int i=1;i<k;i++) {
                if(sum<0) {//sum<0的情况，舍弃之前的left，从i开始一个新的子序列//最优子结构，所以不会错过最终的left
                    sum=0;
                    temp=i;//此时不直接更新left，因为这个新的区间不一定产生满足(sum>MAX)的sum
                }
                sum+=a[i];
                //用它来代替：sum[i]=sum[i-1]>0 ? sum[i-1]+a[i],a[i];
                if(sum>MAX) {//更新MAX的条件
                    MAX=sum;
                    right=i;//更新right
                    left=temp;//选择新的区间之后，才更新新的left
                }
            }
            cout<<MAX<<" "<<a[left]<<" "<<a[right]<<endl;
        }
    }
    return 0;
}

/*
https://blog.csdn.net/qq_38386316/article/details/76694265
6
-2 11 -4 13 -5 -2
20 11 13
*/
