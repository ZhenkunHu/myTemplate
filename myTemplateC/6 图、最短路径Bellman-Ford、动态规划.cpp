#include<bits/stdc++.h>
using namespace std;

int main() {
    int dis[51],i,k,m,n,u[51],v[51],w[51],check,flag;
    int inf=1000000000;
    scanf("%d%d",&m,&n);

    //����� ���ڽӱ�
    for(i=0;i<n;i++)
        scanf("%d%d%d",&u[i],&v[i],&w[i]);

    //��ʼ��dis,������0�Ŷ��㵽�����������ĳ�ʼ·��
    for(i=0;i<m;i++)
        dis[i]=inf;
    dis[0]=0;

    //Bellman-Ford�㷨//˼���Floyd-Warshall�㷨���� ��̬�滮
    for(k=0;k<m-1;k++) {//�Ա�Ϊö�����ģ�m�������ͼ����ຬ��m-1���� ���·��һ���ǲ�������·�ļ�·������֤����
        check=0;//��������ڱ����ɳ�������dis�Ƿ�ᷢ������ �е���ð������
        for(i=0;i<n;i++) {//�ɳ�
            if(dis[v[i]]>dis[u[i]]+w[i]) {
                dis[v[i]]=dis[u[i]]+w[i];
                check=1;//����dis�������£��ı�check��ֵ
            }
        }
        if(check==0) break;//�������disû�и��£��˳�ѭ��
    }

    //��⸺Ȩ��·
    flag=0;
    for(i=0;i<n;i++)
        if(dis[v[i]]>dis[u[i]]+w[i]) flag=1;
    if(flag==1) printf("��ͼ���и�Ȩ��·");
    else {
        for(i=0;i<m;i++)//������ս��
            printf("%d ",dis[i]);
    }

    return 0;
}

/*
6 9
0 1 1
0 2 12
1 2 9
1 3 3
2 4 5
3 2 4
3 4 13
3 5 15
4 5 4

0 1 8 4 13 17
*/
