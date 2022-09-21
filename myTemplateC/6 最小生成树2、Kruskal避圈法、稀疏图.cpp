#include<bits/stdc++.h>
using namespace std;

struct edge {//�洢��
    int u;
    int v;
    int w;
};
struct edge e[10];//����Ĵ�С����ʵ����������ã�Ҫ��m�����ֵ��1
int n,m;
int f[7]={0},sum=0,Count=0;//���鼯��Ҫ�õ���һЩ����//f�����С����ʵ����������ã�Ҫ��n�����ֵ��1
/*//�Լ�д�Ŀ�������
void quicksort(int left,int right) {

    int i,j;
    struct edge t;
    if(left>right)
        return;

    i=left;
    j=right;
    while(i!=j) {
        while(e[j].w>=e[left].w&&i<j)//˳�����Ҫ��Ҫ�ȴ��ұ߿�ʼ��
            j--;
        while(e[i].w<=e[left].w&&i<j)//�ٴ���߿�ʼ��
            i++;

        if(i<j) {//����
            t=e[i];
            e[i]=e[j];
            e[j]=t;
        }
    }
    //���ս���׼����λ����left��i����
    t=e[left];
    e[left]=e[i];
    e[i]=t;

    quicksort(left,i-1);
    quicksort(i+1,right);
    return;
}
*/

bool cmp(edge left,edge right) {
    return left.w<right.w;
}

//���鼯Ѱ�����ȵĺ���
int getf(int v) {
    if(f[v]==v) return v;
    else {
        f[v]=getf(f[v]);//·��ѹ��
        return f[v];
    }
}
//���鼯�ϲ����Ӽ��ϵĺ���
int merge(int v,int u) {
    int t1=getf(v),t2=getf(u);//t1,t2�ֱ���v��u�Ĵ�Boss
    if(t1!=t2) {//�ж��������Ƿ���ͬһ��������
        f[t2]=t1;//����ԭ��
        return 1;
    }
    return 0;
}

int main() {
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
/*
    quicksort(1,m);//�Լ�д�Ŀ�������
*/
    sort(e+1,e+m+1,cmp);
    //���鼯��ʼ��
    for(i=1;i<=n;i++)
        f[i]=i;
    //Kruskal�㷨���Ĳ���
    for(i=1;i<=m;i++) {//��ʼ��С����ö��ÿһ����
        if(merge(e[i].u,e[i].v)) {//�ж�һ���ߵ����������Ƿ��Ѿ���ͨ�����Ƿ���ͬһ������//���Ŀǰ����ͨ����ѡ��������
            Count++;
            sum=sum+e[i].w;
        }
        if(Count==n-1)
            break;
    }
    printf("%d\n",sum);
    return 0;
}
/*
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
