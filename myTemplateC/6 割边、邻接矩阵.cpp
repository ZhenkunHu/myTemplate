#include<bits/stdc++.h>
using namespace std;

int n,m,e[9][9],root;
int num[9],low[9],flag[9],index;//index��������ʱ����ĵ���

//����㷨�ĺ���
void dfs(int cur,int father) {//��Ҫ�����������������ǰ�����ź͸�����ı��
    int i;//child������¼���������е�ǰ����cur�Ķ��Ӹ���
    index++;//ʱ�����1
    num[cur]=index;//��ǰ����cur��ʱ���
    low[cur]=index;//��ǰ����cur�ܹ����ʵ����綥���ʱ������տ�ʼ��Ȼ���Լ���

    for(i=1;i<=n;i++) {//ö���뵱ǰ����cur�б������Ķ���i
        if(e[cur][i]==1) {
            if(num[i]==0) {//�������i��ʱ���Ϊ0��˵������i��û�б����ʹ�//���������ĽǶ���˵����ʱ��iΪcur�Ķ���//book
                dfs(i,cur);//��������������ȱ���

                low[cur]=min(low[cur],low[i]);//���µ�ǰ����cur�ܷ��ʵ����綥���ʱ���

                if(low[i]>num[cur])//����low[i]>num[cur],�������׶����ܻص����Ǹ��
                    printf("%d-%d\n",cur,i);
            }
            else if(i!=father)//�����������i���������ʹ�������������㲻�ǵ�ǰ����cur�ĸ���,��˵����ʱ��iΪcur�����ȣ�
                low[cur]=min(low[cur],num[i]);//�����Ҫ���µ�ǰ�ڵ�cur�ܷ��ʵ����綥���ʱ���
        }
    }
    return;
}

int main() {
    int i,j,x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            e[i][j]=0;

    for(i=1;i<=m;i++) {
        scanf("%d%d",&x,&y);
        e[x][y]=1;
        e[y][x]=1;
    }

    root=1;
    dfs(1,root);//��1�Ŷ������������ȱ���

    return 0;
}
/*
6 6
1 4
1 3
4 2
3 2
2 5
5 6
5-6
2-5
���� �� ��������
���ֽṹ����ִ��else��֮���ִ��dfs()֮��Ĵ���
void dfs() {
    if() {
        dfs();
        XXX;
    }
    else {}
}

*/
