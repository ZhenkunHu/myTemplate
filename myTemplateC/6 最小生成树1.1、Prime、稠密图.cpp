#include<bits/stdc++.h>//���Dijkstra�㷨
using namespace std;

int main() {
    int n,m,i,j,k,Min,t1,t2,t3;
    int e[7][7],dis[7],book[7];//��book�����ʼ��
    int inf=99999999;
    int Count=0,sum=0;//Count������¼�������ж���ĸ�����sum�����洢·��֮��

    scanf("%d%d",&n,&m);
    //��ʼ��
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i==j) e[i][j]=0;//�����������Ԫ//��ͬ������
            else e[i][j]=inf;
    //��ʼ�����
    for(i=1;i<=m;i++) {
        scanf("%d%d%d",&t1,&t2,&t3);
        e[t1][t2]=t3;//����ͼ
        e[t2][t1]=t3;
    }

    //��ʼ��dis���飬������1�Ŷ��㵽��������ĳ�ʼ���룬��Ϊ��ǰ��������ֻ��һ�Ŷ���
    for(i=1;i<=n;i++)
        dis[i]=e[1][i];
    //��ʼ��
    memset(book,0,sizeof(book));
    book[1]=1;//��1�Ŷ������������

    //Prim���Ĳ��ֿ�ʼ
    Count++;
    while(Count<n) {
        Min=inf;
        for(i=1;i<=n;i++) {//ѡ��������������Ķ���
            if(book[i]==0&&dis[i]<Min) {
                Min=dis[i];
                j=i;
            }
        }
        book[j]=1;
        Count++;
        sum=sum+dis[j];
        //�ɳڣ�ɨ�赱ǰ����j���еıߣ�����jΪ�м�㣬������������ÿһ����������ľ���
        for(k=1;k<=n;k++) {
            if(book[k]==0&&dis[k]>e[j][k])
                dis[k]=e[j][k];
        }
    }
    printf("%d\n",sum);
    return 0;
}
/*
̰�� ���Dijkstra�㷨�����ɳڲ�����һ��
6 9
2 4 11
3 5 13
4 6 3
5 6 4
2 3 6
4 5 7
1 2 1
3 4 9
1 3 2
output:19
*/
