#include<bits/stdc++.h>
using namespace std;

int n,m,e[9][9],root;
int num[9],low[9],flag[9],index;//index��������ʱ����ĵ���

//����㷨�ĺ���
void dfs(int cur,int father) {//��Ҫ�����������������ǰ�����ź͸�����ı��
    int child=0,i;//child������¼���������е�ǰ����cur�Ķ��Ӹ���
    index++;//ʱ�����1
    num[cur]=index;//��ǰ����cur��ʱ���
    low[cur]=index;//��ǰ����cur�ܹ����ʵ����綥���ʱ������տ�ʼ��Ȼ���Լ���

    for(i=1;i<=n;i++) {//ö���뵱ǰ����cur�б������Ķ���i
        if(e[cur][i]==1) {
            if(num[i]==0) {//�������i��ʱ���Ϊ0��˵������i��û�б����ʹ�//���������ĽǶ���˵����ʱ��iΪcur�Ķ���//book
                child++;
                dfs(i,cur);//��������������ȱ���

                low[cur]=min(low[cur],low[i]);//���µ�ǰ����cur�ܷ��ʵ����綥���ʱ���

                if(cur!=root&&low[i]>=num[cur])//�����ǰ���㲻�Ǹ��ڵ㲢������low[i]>=num[cur],��ǰ����Ϊ���
                    flag[cur]=1;
                if(cur==root&&child==2)//�����ǰ�����Ǹ��ڵ㣬���������и��ڵ����Ҫ���������ӣ���ô������ڵ���Ǹ��
                    flag[cur]=1;
            }//if(num[i]==0)
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

    for(i=1;i<=n;i++)
        if(flag[i]==1)
    printf("%d ",i);

    return 0;
}
/*
6 7
1 4
1 3
4 2
3 2
2 5
2 6
5 6
2
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
