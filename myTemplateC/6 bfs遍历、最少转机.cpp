#include<bits/stdc++.h>
using namespace std;

struct note {
    int x;//城市标号
    int y;//转机次数
};

const int infi=1000000000;

int main() {
    note tem;
    queue<note> que;
    int n,m,start,end;
    cin>>n>>m>>start>>end;
    int e[51][51]={0},book[51]={0};

    for(int i=1;i<=n;i++)//初始化矩阵
        for(int j=1;j<=n;j++)
            if(i==j) e[i][j]=0;
            else e[i][j]=infi;
    for(int i=1;i<=m;i++) {//读入边
        int a,b;
        cin>>a>>b;
        e[a][b]=1;
        e[b][a]=1;
    }

    book[start]=1;
    tem.x=start;tem.y=0;
    que.push(tem);
    while(!que.empty()) {
        int cur=que.front().x;
        int flag=1;
        for(int i=1;i<=n;i++) {
            if(e[cur][i]!=infi&&book[i]==0) {//e[cur][i]!=infi比e[cur][i]==1更具一般性
                book[i]=1;
                tem.x=i;tem.y=que.front().y+1;
                que.push(tem);
            }
            if(que.back().x==end) {
                flag=0;
                break;
            }
        }
        if(!flag) break;
        que.pop();
    }
    cout<<que.back().y<<endl;
    return 0;
}
/*
5 7 1 5
1 2
1 3
2 3
2 4
3 4
3 5
4 5
2
*/
