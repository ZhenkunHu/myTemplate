#include<iostream>
using namespace std;
int sum=0;
int e[10][10]={0};
int n;
int book[10]={0};
void dfs(int cur) {//从逻辑上看，递归定义；从物理上看，栈；递归和遍历好像不一样
    printf("%d ",cur);
    sum++;
    if(sum==n) return;
    for(int i=1;i<=n;i++) {
        if(e[cur][i]==1&&book[i]==0) {
            book[i]=1;
            dfs(i);
        }
    }
    return;
}
int main() {
    int v;
    cin>>n>>v;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j) e[i][j]=0;
            else e[i][j]=99999999;
    for(int i=0;i<v;i++) {
        int a,b;
        cin>>a>>b;
        e[a][b]=1;
        e[b][a]=1;
    }

    book[1]=1;
    dfs(1);
    return 0;
}
/*
5 5
1 2
1 3
1 5
2 4
3 5
1 2 4 3 5
*/
