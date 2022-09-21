#include<bits/stdc++.h>
using namespace std;

string tree[10000];
queue<string> que;

int main() {
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++) {
        cin>>tree[i];
    }

    que.push(tree[1]);
    cout<<tree[1]<<" ";

    int sum=1;
    while(!que.empty()&&sum<=n) { //队列非空，树非空

        int tem=sum*2;
        if(tree[tem]!="#") {
            que.push(tree[tem]);
            cout<<tree[tem]<<" ";
        }

        int tem2=tem+1;
        if(tree[tem2]!="#") {
            que.push(tree[tem2]);
            cout<<tree[tem2]<<" ";
        }

        que.pop();
        sum++;
    }

    return 0;
}

/*
7
3 9 20 # # 15 7
*/
