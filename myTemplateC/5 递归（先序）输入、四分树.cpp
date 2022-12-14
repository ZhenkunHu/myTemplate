//递归（先序）输入，所以不必建树，直接用树
#include<iostream>
#include<cstring>
using namespace std;

const int len=32;
const int maxn=1024+10;
char s[maxn];
int buf[len][len],cnt;

//把字符串是[p..]导出到以（r,c）为左上角，边长为 w 的缓冲区中
//2 1
//3 4
void draw(const char* s,int& p,int r,int c,int w)
{
	char ch=s[p++];
	if(ch=='p')
	{
		draw(s,p,r,c+w/2,w/2);//1
		draw(s,p,r,c,w/2);//2
		draw(s,p,r+w/2,c,w/2);//3
		draw(s,p,r+w/2,c+w/2,w/2);//4
	}
	else if(ch=='f')//画黑像素，白像素不画
	{
		for(int i=r;i<r+w;i++)
		    for(int j=c;j<c+w;j++)
			    if(buf[i][j]==0) {buf[i][j]=1;cnt++;}
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(buf,0,sizeof(buf));
		cnt=0;
		for(int i=0;i<2;i++)
		{
			scanf("%s",s);
			int p=0;
			draw(s,p,0,0,len);
		}
		printf("There are %d black pixels.\n",cnt);
	}
	return 0;
}
