#include <bits/stdc++.h>
using namespace std;

int f[1000];

void init(int n) {
    for(int i=0;i<n;i++)
        f[i]=i;
}

//int findset(int x) { return pa[x] != x ? pa[x] = findset(pa[x]) : x; }
//get father 类比迷宫路径的广搜father
int getf(int v) {
    if(f[v]==v) return v; //每个团伙的头都是f[v]==v
    else {
        f[v]=getf(f[v]);//路径压缩，更快找到最终BOSS
        return f[v];//可以//f[v]=getf(f[v]);然后return getf(f[v]);
    }
}

//合并两子集合的函数
void merge(int u, int v) {
    int t1=getf(u);
    int t2=getf(v);

    if(t1!=t2) f[t2]=t1;//不是t1=f[t2] 靠左原则
}

int main() {

    int m,n;
    scanf("%d%d",&m,&n);

    init(m);

    int t1,t2;
    for(int i=0;i<n;i++) {
        scanf("%d%d",&t1,&t2);
        merge(t1,t2);
    }

//最后扫描有多少个独立的犯罪团伙
    int sum=0;
    for(int i=0;i<m;i++)
        if(f[i]==i)
            sum++;

    printf("%d\n",sum);

    return 0;
}

/*
input:
10 9
1 2
3 4
5 2
4 6
2 6
8 7
9 7
1 6
2 4
output:
3
*/
