//ͬʱ������ŷ����·��ŷ����·��ŷ����·�������������
void euler(int u) {
    for(int v=0;v<n;v++) if(G[u][v]&&!vis[u][v]) {
        vis[u][v]=vis[v][u]=1;//����������ͼ������ͼʱӦ����vis[u][v]=1;
        enler(v);
        printf("%d %d\n",u,v);//�����������ӡ��Ӧ����push,ѹ��ջ��
    }
}
