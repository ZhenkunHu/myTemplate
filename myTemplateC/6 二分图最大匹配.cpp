#include<bits/stdc++.h>
using namespace std;

int e[101][101];
int match[101];
int book[101];
int n,m;

//����·
int dfs(int u) {
    for(int i=1;i<=n;i++) {
        if(book[i]==0&&e[u][i]==1) {
            book[i]=1;//��ǵ�i�ѷ��ʹ�
            if(match[i]==0||dfs(match[i])) {//�����iδ��Ի����ҵ����µ����
                match[i]=u;//������Թ�ϵ
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int i,j,t1,t2,sum=0;
    scanf("%d%d",&n,&m);//n����,m����

    for(i=1;i<=m;i++) {//�����
        scanf("%d%d",&t1,&t2);
        e[t1][t2]=1;
    }

    for(i=1;i<=n;i++)
        match[i]=0;

    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) book[j]=0;//����ϴ�����ʱ�ı��
        if(dfs(i)) sum++;//Ѱ������·������ҵ����������1
    }

    printf("%d\n",sum);

    return 0;
}
/*
3 5
1 1
1 2
2 2
2 3
3 1
3
*/
