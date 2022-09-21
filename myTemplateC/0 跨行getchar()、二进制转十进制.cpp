/*
UVa 213
$#**\
code[1][0]=$
code[2][0]=#
code[2][1]=*
code[2][2]=*
code[3][0]=\
0100000101101100011100101000
##*\$
*/
#include<stdio.h>
#include<string.h>
int readchar()//跨行getchar()
{
	for(;;)
	{
		int ch=getchar();
		if(ch!='\n'&&ch!='\r') return ch;
	}
}

int readint(int c)//二转十
{
	int v=0;
	while(c--) v=v*2+readchar()-'0';//二进制转十进制
	return v;
}

int code[8][1<<8];//在二进制中，把1向左移动8位

int readcodes()//存储代码头
{
	memset(code,0,sizeof(code));
	code[1][0]=readchar();//直接调到下一行开始读取。如果输入已经结束，会读到EOF
	for(int len=2;len<=7;len++)
	{
		for(int i=0;i<(1<<len)-1;i++)
		{
			int ch=getchar();
			if(ch==EOF) return 0;
			if(ch=='\n'||ch=='\r') return 1;
			code[len][i]=ch;
		}
    }
    return 1;
}

void printcodes()//调试函数
{
	for(int len=1;len<=7;len++)
	    for(int i=0;i<(1<<len)-1;i++)
	    {
	    	if(code[len][i]==0) return;
	    	printf("code[%d][%d]=%c\n",len,i,code[len][i]);
	    }
}

int main()
{
	while(readcodes())
	{
printcodes();
      for(;;)
      {
    	  int len=readint(3);
    	  if(len==0) break;
    	  for(;;)
    	  {
    		  int v=readint(len);
    		  if(v==(1<<len)-1) break;
    		  putchar(code[len][v]);
    	  }
      }
      putchar('\n');
	}
	return 0;
}
