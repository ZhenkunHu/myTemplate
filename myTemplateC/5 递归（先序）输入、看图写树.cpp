#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

const int maxn = 200 + 5;
int n;
char buf[maxn][maxn];

//�ݹ��������������ַ�buf[r][c]Ϊ������
void dfs(int r,int c) {//�������ж��������������
    printf("%c(",buf[r][c]);
    if(r+1<n&&buf[r+1][c]=='|') {//������
        int i=c;
        while(i-1>=0&&buf[r+2][i-1]=='-') i--;//�ҡ�----������߽�
        while(buf[r+2][i]=='-'&&buf[r+3][i]!='\0') {//!='\0'
            if(!isspace(buf[r+3][i])) dfs(r+3,i);//fgets����ġ�\n��Ҳ����isspace()
            i++;
        }
    }
    printf(")");//ָ������ͷ
}

void solve() {//��Ϊ��������Ƚϼ򵥣������ô�������
    n=0;
    for(;;) {//���벿��
        fgets(buf[n],maxn,stdin);//����������buf[0]
        if(buf[n][0]=='#') break;else n++;
    }
    printf("(");
    if(n) {
        for(int i=0;i<strlen(buf[0]);i++)
            if(buf[0][i]!=' ') { dfs(0,i);break;}
    }
    printf(")\n");
}

int main() {
    int T;
    fgets(buf[0],maxn,stdin);//fgets()��ʹ��
    sscanf(buf[0],"%d",&T);//sscanf()��ʹ��
    while(T--) solve();
    return 0;
}
