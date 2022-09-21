#include <stdio.h>

int gra[51][51];
int book[51];
int dis[51];

int inf = 2100000000;

int main() {

    int m,n;
    scanf("%d%d",&m,&n);

    //初始化
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            if(i==j) gra[i][j]=0;
            else gra[i][j]=inf;

    //输入边
    int s,e,w;
    for(int i=0;i<n;i++) {
        scanf("%d%d%d",&s,&e,&w);
        gra[s][e]=w;
    }

    //初始化0点到其他点的距离
    for(int i=0;i<m;i++) {
        dis[i]=gra[0][i];
    }

    //book数组初始化 标记点 因为以点为中心
    for(int i=0;i<m;i++)
        book[i]=0;
    book[0]=1;

    //Dijkstra 核心算法 以点为中心
    for(int i=0;i<m-1;i++) {
        //找到离0号顶点最近的顶点
        int u=0,min_v=inf;
        for(int j=0;j<m;j++) {
            if(dis[j]<min_v&&book[j]==0) { //贪心 以dis[]为过程
                min_v=dis[j];
                u=j;
            }
        }
        book[u]=1;
/*
 //输出 过程
for(int j=0;j<m;j++) {
    printf("%10d ",dis[j]);
}
printf("\n");
*/
        //松弛
        for(int j=0;j<m;j++) {
            if(gra[u][j]<inf)  //健壮性
                if(dis[j]>dis[u]+gra[u][j])//多做了一部分判断，已经确定的dis不会再变化
                    dis[j]=dis[u]+gra[u][j];
        }
    }

    //输出
    for(int j=0;j<m;j++) {
        printf("%d ",dis[j]);
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
贪心过程
         0          1         12 2100000000 2100000000 2100000000
         0          1         10          4 2100000000 2100000000
         0          1          8          4         17         19
         0          1          8          4         13         19
         0          1          8          4         13         17
0 1 8 4 13 17
*/
