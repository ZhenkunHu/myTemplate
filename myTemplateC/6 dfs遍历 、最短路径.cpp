#include<bits/stdc++.h>
using namespace std;

int min0=99999999,book[101],n,e[101][101];

void dfs(int cur,int dis) {
    int i;
    if(dis>min0) return;//表示障碍物
    if(cur==n) {
        if(dis<min0) min0=dis;
        return;
    }

    for(i=1;i<=n;i++) {
        if(e[cur][i]!=99999999&&book[i]==0) {
            book[i]=1;
            dfs(i,dis+e[cur][i]);
            book[i]=0; //因为要返回，所以要取消标记
        }
    }
    return;
}

int main() {
    int i,j,m,a,b,c;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i==j) e[i][j]=0;
            else e[i][j]=99999999;
    for(i=1;i<=m;i++) {
        scanf("%d%d%d",&a,&b,&c);
        e[a][b]=c;
    }
    book[1]=1;
    dfs(1,0);
    printf("%d\n",min0);
    return 0;
}
