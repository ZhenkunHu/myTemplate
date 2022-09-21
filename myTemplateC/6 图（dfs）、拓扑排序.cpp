#include<cstdio>
#include<cstring>
const int maxn = 1000;
int n, m, G[maxn][maxn], c[maxn], topo[maxn], t;

bool dfs(int u){
  c[u] = -1;//访问标志（c[u]=0表示未访问；c[u]=1表示u已访问并且他的子孙也已访问；c[u]=-1表示在栈帧中）
  for(int v = 0; v < n; v++) if(G[u][v]) {
    if(c[v]<0) return false;//存在有向环，失败退出（又回到了在栈帧中的结点，来判断回路）
    else if(!c[v]) dfs(v);
  }
  c[u] = 1; topo[--t]=u;//因为后进先出
  return true;
}

bool toposort(){
  t = n;
  memset(c, 0, sizeof(c));
  for(int u = 0; u < n; u++) if(!c[u])
    if(!dfs(u)) return false;//如果dfs出错了，则toposort也出错
  return true;
}

int main() {
  while(scanf("%d%d", &n, &m) == 2 && n) {
    memset(G, 0, sizeof(G));
    for(int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v); u--; v--;//按从零开始处理
      G[u][v] = 1;
    }
    if(toposort()) {
      for(int i = 0; i < n-1; i++)
        printf("%d ", topo[i]+1);
      printf("%d\n", topo[n-1]+1);
    }
    else
      printf("No\n"); // 题目没说无解输出什么，应该是保证有解吧
  }
}
/*
5 4
1 2
2 3
1 3
1 5
0 0
*/
