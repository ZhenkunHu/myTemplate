#include <stdio.h>

int gra[51][51];

int inf = 1000000000;//因为2100000000*2溢出

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

    //Floyd 核心代码 从i号顶点到j号顶点只经过前k号点的最短路径 动态规划 以m个点为过程
    for(int k=0;k<m;k++) {
        for(int i=0;i<m;i++) {
            for(int j=0;j<m;j++) {
                if(gra[i][j]>gra[i][k]+gra[k][j])
                    gra[i][j]=gra[i][k]+gra[k][j];
            }
        }
    }

    //输出
    for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            printf("%10d ",gra[i][j]);
        }
        printf("\n");
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
动态规划过程
         0          1          8          4         13         17
1000000000          0          7          3         12         16
1000000000 1000000000          0 1000000000          5          9
1000000000 1000000000          4          0          9         13
1000000000 1000000000 1000000000 1000000000          0          4
1000000000 1000000000 1000000000 1000000000 1000000000          0
0 1 8 4 13 17
*/
