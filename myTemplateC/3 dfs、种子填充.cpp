#include<iostream>
#include<cstring>
using namespace std;

const int maxn=100+5;
char pic[maxn][maxn];
int m,n,idx[maxn][maxn];

void dfs(int r,int c,int id)
{
	if(r<0||r>=m|c<0||c>=n) return;//“出界”的格子
	if(idx[r][c]>0||pic[r][c]!='@') return;//已经访问过或不是'@'的格子
	idx[r][c]=id;//连通分量编号
	for(int dr=-1;dr<=1;dr++)//继续遍历 可以用next数组。区别：8个方向
	    for(int dc=-1;dc<=1;dc++)
		    if(dr!=0||dc!=0) dfs(r+dr,c+dr,id);
}

int main()
{
	while(scanf("%d%d",&m,&n)==2&&m&&n)
	{
		for(int i=0;i<m;i++) scanf("%s",pic[i]);
		memset(idx,0,sizeof(idx));
		int cnt=0;
		for(int i=0;i<m;i++)
		    for(int j=0;j<n;j++)
		        if(idx[i][j]==0&&pic[i][j]=='@') dfs(i,j,++cnt);//dfs()的参数：把dfs（）作为一个普通函数来确认参数
	    printf("%d\n",cnt);
	}
	return 0;
}
