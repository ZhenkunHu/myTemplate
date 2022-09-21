//全面思想，手动模拟。更好的理解代码。 
#include<cstdio>
#include<algorithm> 
using namespace std;

int n;
const int maxn=100000+10;
int left[maxn],right[maxn];

void link(int l,int r)//复杂链式结构常用到辅助函数。实现连接。 
{
	right[l]=r;left[r]=l;
}

int main()
{
    int m,kase=0;
    while(scanf("%d%d",&n,&m)==2)//双向循环链表 
    {
    	for(int i=1;i<=n;i++)
    	{
    		left[i]=i-1;right[i]=(i+1)%(n+1);
		}
		right[0]=1;left[0]=n;
		int op,x,y,inv=0;
		
		while(m--)
		{
			scanf("%d",&op);
			if(op==4) inv=!inv;//对于耗时操作进行标记处理。 
			else
			{
				scanf("%d%d",&x,&y);//这一段代码先处理简单情况。 
				if(op==3&&right[y]==x) swap(x,y);
				if(op!=3&&inv) op=3-op;//因为对耗时操作进行标记处理，所以需要转化。 
				if(op==1&&x==left[y]) continue;
				if(op==2&&x==right[y]) continue;
				
				int lx=left[x],rx=right[x],ly=left[y],ry=right[y]; 
				if(op==1){
					link(lx,rx);link(ly,x);link(x,y);// 移动=连接+插入 
				}
				else if(op==2){
					link(lx,rx);link(y,x);link(x,ry);//移动=连接+插入 
				}
				else if(op==3){
					if(right[x]==y) {link(lx,y);link(y,x);link(x,ry);}//交换的两种形式。 
					else {link(lx,y);link(y,rx);link(ly,x);link(x,ry);}
				}
			}
		}
		
		int b=0;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			b=right[b];
			if(i%2==1) ans+=b;
		}
		if(inv&&n%2==0) ans=(long long)n*(n+1)/2-ans;//如果反转并且有偶数个结点，则奇数和=总和-偶数和。 
		printf("Case %d: %lld\n",++kase,ans);//printf("%Case %d: %lld\n",++kase,ans);注意这个格式控制非常严肃。 
	}
    return 0;
}

