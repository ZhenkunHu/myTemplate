#include<bits/stdc++.h>
using namespace std;

int main() {
    int dis[51],i,k,m,n,u[51],v[51],w[51],check,flag;
    int inf=1000000000;
    scanf("%d%d",&m,&n);

    //读入边 简单邻接表
    for(i=0;i<n;i++)
        scanf("%d%d%d",&u[i],&v[i],&w[i]);

    //初始化dis,这里是0号顶点到其余各个顶点的初始路程
    for(i=0;i<m;i++)
        dis[i]=inf;
    dis[0]=0;

    //Bellman-Ford算法//思想和Floyd-Warshall算法相似 动态规划
    for(k=0;k<m-1;k++) {//以边为枚举中心，m个顶点的图中最多含有m-1条边 最短路径一定是不包含回路的简单路径（反证法）
        check=0;//用来标记在本轮松弛中数组dis是否会发生更新 有点像冒泡排序
        for(i=0;i<n;i++) {//松弛
            if(dis[v[i]]>dis[u[i]]+w[i]) {
                dis[v[i]]=dis[u[i]]+w[i];
                check=1;//数组dis发生更新，改变check的值
            }
        }
        if(check==0) break;//如果数组dis没有更新，退出循环
    }

    //检测负权回路
    flag=0;
    for(i=0;i<n;i++)
        if(dis[v[i]]>dis[u[i]]+w[i]) flag=1;
    if(flag==1) printf("此图含有负权回路");
    else {
        for(i=0;i<m;i++)//输出最终结果
            printf("%d ",dis[i]);
    }

    return 0;
}

/*
6 9
0 1 1
0 2 12
1 2 9
1 3 3
2 4 5
3 2 4
3 4 13
3 5 15
4 5 4

0 1 8 4 13 17
*/
