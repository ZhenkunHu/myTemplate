#include<bits/stdc++.h>
using namespace std;

int n,c[8],tot=0;
int vis[2][8];

//八皇后问题
void search(int cur) {
    if(cur==n) tot++;//递归边界。只要走到这里，所有皇后必然不冲突
    else for(int i=0;i<n;i++) {
        int ok=1;
        c[cur]=i;//尝试把cur行的皇后放到第i列
        for(int j=0;j<cur;j++)//检查是否和前面的皇后冲突
            if(c[cur]==c[j]||cur-c[cur]==j-c[j]||cur+c[cur]==j+c[j])//后两个判断对角线
                {ok=0;break;}
        if(ok) search(cur+1);//如果合法，则继续递归
    }
}

//这个有毛病
void search2(int cur) {
    if(cur==n) tot++;
    else for(int i=0;i<n;i++) {
        if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+n]) {//利用二维数组直接判断
            c[cur]=i;//如果不用打印解，整个c数组都可以省略
            vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=1;//修改全局变量
            search2(cur+1);
            vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=0;//切记！一定要改回来
        }
    }
}

int main() {
    scanf("%d",&n);
    search(0);
    printf("%d\n",tot);

/*
    tot=0;
    memset(vis,0,sizeof(vis));
    search2(0);
    printf("%d\n",tot);
*/

    return 0;
}
