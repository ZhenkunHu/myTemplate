#include<bits/stdc++.h>
using namespace std;

struct edge {//存储边
    int u;
    int v;
    int w;
};
struct edge e[10];//数组的大小根据实际情况来设置，要比m的最大值大1
int n,m;
int f[7]={0},sum=0,Count=0;//并查集需要用到的一些变量//f数组大小根据实际情况来设置，要比n的最大值大1
/*//自己写的快速排序
void quicksort(int left,int right) {

    int i,j;
    struct edge t;
    if(left>right)
        return;

    i=left;
    j=right;
    while(i!=j) {
        while(e[j].w>=e[left].w&&i<j)//顺序很重要，要先从右边开始找
            j--;
        while(e[i].w<=e[left].w&&i<j)//再从左边开始找
            i++;

        if(i<j) {//交换
            t=e[i];
            e[i]=e[j];
            e[j]=t;
        }
    }
    //最终将基准数归位，将left和i互换
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

//并查集寻找祖先的函数
int getf(int v) {
    if(f[v]==v) return v;
    else {
        f[v]=getf(f[v]);//路径压缩
        return f[v];
    }
}
//并查集合并两子集合的函数
int merge(int v,int u) {
    int t1=getf(v),t2=getf(u);//t1,t2分别是v和u的大Boss
    if(t1!=t2) {//判断两个点是否在同一个集合中
        f[t2]=t1;//靠左原则
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
    quicksort(1,m);//自己写的快速排序
*/
    sort(e+1,e+m+1,cmp);
    //并查集初始化
    for(i=1;i<=n;i++)
        f[i]=i;
    //Kruskal算法核心部分
    for(i=1;i<=m;i++) {//开始从小到大枚举每一条边
        if(merge(e[i].u,e[i].v)) {//判断一条边的两个顶点是否已经连通，即是否在同一个集合//如果目前不连通，则选用这条边
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
