#include<cstdio>
#include<cstring>
const int maxn = 1000;
int n, m, G[maxn][maxn], c[maxn], topo[maxn], t;

bool dfs(int u){
  c[u] = -1;//���ʱ�־��c[u]=0��ʾδ���ʣ�c[u]=1��ʾu�ѷ��ʲ�����������Ҳ�ѷ��ʣ�c[u]=-1��ʾ��ջ֡�У�
  for(int v = 0; v < n; v++) if(G[u][v]) {
    if(c[v]<0) return false;//�������򻷣�ʧ���˳����ֻص�����ջ֡�еĽ�㣬���жϻ�·��
    else if(!c[v]) dfs(v);
  }
  c[u] = 1; topo[--t]=u;//��Ϊ����ȳ�
  return true;
}

bool toposort(){
  t = n;
  memset(c, 0, sizeof(c));
  for(int u = 0; u < n; u++) if(!c[u])
    if(!dfs(u)) return false;//���dfs�����ˣ���toposortҲ����
  return true;
}

int main() {
  while(scanf("%d%d", &n, &m) == 2 && n) {
    memset(G, 0, sizeof(G));
    for(int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v); u--; v--;//�����㿪ʼ����
      G[u][v] = 1;
    }
    if(toposort()) {
      for(int i = 0; i < n-1; i++)
        printf("%d ", topo[i]+1);
      printf("%d\n", topo[n-1]+1);
    }
    else
      printf("No\n"); // ��Ŀû˵�޽����ʲô��Ӧ���Ǳ�֤�н��
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
