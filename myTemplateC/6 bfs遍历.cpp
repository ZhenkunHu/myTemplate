#include<iostream>
#include<queue>
using namespace std;

int e[10][10]={0};
int n;
int book[10]={0};
queue<int> que;
int sum=1;

void bfs(int cur) {
    while(!que.empty()) {
        cur=que.front();
        for(int i=1;i<=n;i++) {
            if(e[cur][i]==1&&book[i]==0) {
                book[i]=0;
                sum++;
                que.push(i);
            }
            if(sum==n) break;
        }
        cout<<que.front()<<" ";
        que.pop();
    }
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
    que.push(1);
    bfs(1);
    return 0;
}
/*
5 5
1 2
1 3
1 5
2 4
3 5
1 2 3 5 4
*/
