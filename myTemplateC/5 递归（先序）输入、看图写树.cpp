#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

const int maxn = 200 + 5;
int n;
char buf[maxn][maxn];

//递归遍历并且输出以字符buf[r][c]为根的树
void dfs(int r,int c) {//用缩进判断来代替这个括号
    printf("%c(",buf[r][c]);
    if(r+1<n&&buf[r+1][c]=='|') {//有子树
        int i=c;
        while(i-1>=0&&buf[r+2][i-1]=='-') i--;//找“----”的左边界
        while(buf[r+2][i]=='-'&&buf[r+3][i]!='\0') {//!='\0'
            if(!isspace(buf[r+3][i])) dfs(r+3,i);//fgets读入的“\n”也满足isspace()
            i++;
        }
    }
    printf(")");//指令在两头
}

void solve() {//因为横向分析比较简单，而且让代码更简洁
    n=0;
    for(;;) {//输入部分
        fgets(buf[n],maxn,stdin);//重新输入了buf[0]
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
    fgets(buf[0],maxn,stdin);//fgets()的使用
    sscanf(buf[0],"%d",&T);//sscanf()的使用
    while(T--) solve();
    return 0;
}
