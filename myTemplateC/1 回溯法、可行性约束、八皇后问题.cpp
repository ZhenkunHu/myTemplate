#include<bits/stdc++.h>
using namespace std;

int n,c[8],tot=0;
int vis[2][8];

//�˻ʺ�����
void search(int cur) {
    if(cur==n) tot++;//�ݹ�߽硣ֻҪ�ߵ�������лʺ��Ȼ����ͻ
    else for(int i=0;i<n;i++) {
        int ok=1;
        c[cur]=i;//���԰�cur�еĻʺ�ŵ���i��
        for(int j=0;j<cur;j++)//����Ƿ��ǰ��Ļʺ��ͻ
            if(c[cur]==c[j]||cur-c[cur]==j-c[j]||cur+c[cur]==j+c[j])//�������ж϶Խ���
                {ok=0;break;}
        if(ok) search(cur+1);//����Ϸ���������ݹ�
    }
}

//�����ë��
void search2(int cur) {
    if(cur==n) tot++;
    else for(int i=0;i<n;i++) {
        if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+n]) {//���ö�ά����ֱ���ж�
            c[cur]=i;//������ô�ӡ�⣬����c���鶼����ʡ��
            vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=1;//�޸�ȫ�ֱ���
            search2(cur+1);
            vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=0;//�мǣ�һ��Ҫ�Ļ���
        }
    }
}

int main() {
    scanf("%d",&n);
    search(0);
    printf("%d\n",tot);

/*
    tot=0;
    memset(vis,0,sizeof(vis));
    search2(0);
    printf("%d\n",tot);
*/

    return 0;
}
