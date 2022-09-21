#include<bits/stdc++.h>
using namespace std;

int n,m,e[9][9],root;
int num[9],low[9],flag[9],index;//index用来进行时间戳的递增

//割点算法的核心
void dfs(int cur,int father) {//需要传入的两个参数，当前顶点编号和父顶点的编号
    int child=0,i;//child用来记录在生成树中当前顶点cur的儿子个数
    index++;//时间戳加1
    num[cur]=index;//当前顶点cur的时间戳
    low[cur]=index;//当前顶点cur能够访问到最早顶点的时间戳，刚开始当然是自己啦

    for(i=1;i<=n;i++) {//枚举与当前顶点cur有边相连的顶点i
        if(e[cur][i]==1) {
            if(num[i]==0) {//如果顶点i的时间戳为0，说明顶点i还没有被访问过//从生成树的角度来说，此时的i为cur的儿子//book
                child++;
                dfs(i,cur);//继续往下深度优先遍历

                low[cur]=min(low[cur],low[i]);//更新当前顶点cur能访问到最早顶点的时间戳

                if(cur!=root&&low[i]>=num[cur])//如果当前顶点不是根节点并且满足low[i]>=num[cur],则当前顶点为割点
                    flag[cur]=1;
                if(cur==root&&child==2)//如果当前顶点是根节点，在生成树中根节点必须要有两个儿子，那么这个根节点才是割点
                    flag[cur]=1;
            }//if(num[i]==0)
            else if(i!=father)//否则如果顶点i曾经被访问过，并且这个顶点不是当前顶点cur的父亲,则说明此时的i为cur的祖先，
                low[cur]=min(low[cur],num[i]);//因此需要更新当前节点cur能访问到最早顶点的时间戳
        }
    }
    return;
}

int main() {
    int i,j,x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            e[i][j]=0;

    for(i=1;i<=m;i++) {
        scanf("%d%d",&x,&y);
        e[x][y]=1;
        e[y][x]=1;
    }

    root=1;
    dfs(1,root);//从1号顶点进行深度优先遍历

    for(i=1;i<=n;i++)
        if(flag[i]==1)
    printf("%d ",i);

    return 0;
}
/*
6 7
1 4
1 3
4 2
3 2
2 5
2 6
5 6
2
过程 与 描述过程
这种结构，先执行else，之后才执行dfs()之后的代码
void dfs() {
    if() {
        dfs();
        XXX;
    }
    else {}
}
*/
