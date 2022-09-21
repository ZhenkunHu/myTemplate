//同时适用于欧拉道路和欧拉回路，欧拉道路参数必须是起点
void euler(int u) {
    for(int v=0;v<n;v++) if(G[u][v]&&!vis[u][v]) {
        vis[u][v]=vis[v][u]=1;//这里是有向图，有向图时应换成vis[u][v]=1;
        enler(v);
        printf("%d %d\n",u,v);//这里是逆序打印，应换成push,压入栈内
    }
}
