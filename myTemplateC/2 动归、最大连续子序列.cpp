#include<bits/stdc++.h>
using namespace std;

const int Max=10010;

/* ö���Ӵ� ֪ʶä��
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

ע��i��j
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
����������һ�������ӽṹ�������ҵ�n����������Ӷκͣ���ôҪ�ҵ�n-1����������Ӷκ�
������b[i]����ʾa[0]...a[i]������Ӷκͣ�b[i]�޷����������:
(1)����Ӷ�һֱ������a[i] ��(2)��a[i]Ϊ�׵��µ��Ӷ�

//���������
int MaxSubSequence(int a[]) {
    int Max=MaxSub[0]=a[0];
    for(int i=1;i<n;i++) {
        MaxSub[i]=(MaxSub[i-1]>0 ? MaxSub[i-1]+a[i]:a[i]);//״̬ת�Ʒ���
        if(MaxSub[i]>Max)//���ֵһ���ڶ�ζ�̬�滮�г���
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
            if(a[i]>0) flag=0;//�������������flag=0
        }

        int sum=a[0],left=0,temp,right=0;
        int MAX=0;
        if(flag) cout<<MAX<<" "<<a[0]<<" "<<a[k-1]<<endl;
        else {
            MAX=a[0];
            left=right=0;
            for(int i=1;i<k;i++) {
                if(sum<0) {//sum<0�����������֮ǰ��left����i��ʼһ���µ�������//�����ӽṹ�����Բ��������յ�left
                    sum=0;
                    temp=i;//��ʱ��ֱ�Ӹ���left����Ϊ����µ����䲻һ����������(sum>MAX)��sum
                }
                sum+=a[i];
                //���������棺sum[i]=sum[i-1]>0 ? sum[i-1]+a[i],a[i];
                if(sum>MAX) {//����MAX������
                    MAX=sum;
                    right=i;//����right
                    left=temp;//ѡ���µ�����֮�󣬲Ÿ����µ�left
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
