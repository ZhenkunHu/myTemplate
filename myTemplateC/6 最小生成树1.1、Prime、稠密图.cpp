#include<bits/stdc++.h>//类比Dijkstra算法
using namespace std;

int main() {
    int n,m,i,j,k,Min,t1,t2,t3;
    int e[7][7],dis[7],book[7];//对book数组初始化
    int inf=99999999;
    int Count=0,sum=0;//Count用来记录生成树中顶点的个数，sum用来存储路径之和

    scanf("%d%d",&n,&m);
    //初始化
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i==j) e[i][j]=0;//代码风格，允许多元//不同的命题
            else e[i][j]=inf;
    //开始读入边
    for(i=1;i<=m;i++) {
        scanf("%d%d%d",&t1,&t2,&t3);
        e[t1][t2]=t3;//无向图
        e[t2][t1]=t3;
    }

    //初始化dis数组，这里是1号顶点到各个顶点的初始距离，因为当前生成树中只有一号顶点
    for(i=1;i<=n;i++)
        dis[i]=e[1][i];
    //初始化
    memset(book,0,sizeof(book));
    book[1]=1;//将1号顶点加入生成树

    //Prim核心部分开始
    Count++;
    while(Count<n) {
        Min=inf;
        for(i=1;i<=n;i++) {//选出离生成树最近的顶点
            if(book[i]==0&&dis[i]<Min) {
                Min=dis[i];
                j=i;
            }
        }
        book[j]=1;
        Count++;
        sum=sum+dis[j];
        //松弛：扫描当前顶点j所有的边，再以j为中间点，更新生成树到每一个非树顶点的距离
        for(k=1;k<=n;k++) {
            if(book[k]==0&&dis[k]>e[j][k])
                dis[k]=e[j][k];
        }
    }
    printf("%d\n",sum);
    return 0;
}
/*
贪心 类比Dijkstra算法，仅松弛操作不一样
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
