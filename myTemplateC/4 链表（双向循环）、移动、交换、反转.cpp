//ȫ��˼�룬�ֶ�ģ�⡣���õ������롣 
#include<cstdio>
#include<algorithm> 
using namespace std;

int n;
const int maxn=100000+10;
int left[maxn],right[maxn];

void link(int l,int r)//������ʽ�ṹ���õ�����������ʵ�����ӡ� 
{
	right[l]=r;left[r]=l;
}

int main()
{
    int m,kase=0;
    while(scanf("%d%d",&n,&m)==2)//˫��ѭ������ 
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
			if(op==4) inv=!inv;//���ں�ʱ�������б�Ǵ��� 
			else
			{
				scanf("%d%d",&x,&y);//��һ�δ����ȴ��������� 
				if(op==3&&right[y]==x) swap(x,y);
				if(op!=3&&inv) op=3-op;//��Ϊ�Ժ�ʱ�������б�Ǵ���������Ҫת���� 
				if(op==1&&x==left[y]) continue;
				if(op==2&&x==right[y]) continue;
				
				int lx=left[x],rx=right[x],ly=left[y],ry=right[y]; 
				if(op==1){
					link(lx,rx);link(ly,x);link(x,y);// �ƶ�=����+���� 
				}
				else if(op==2){
					link(lx,rx);link(y,x);link(x,ry);//�ƶ�=����+���� 
				}
				else if(op==3){
					if(right[x]==y) {link(lx,y);link(y,x);link(x,ry);}//������������ʽ�� 
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
		if(inv&&n%2==0) ans=(long long)n*(n+1)/2-ans;//�����ת������ż������㣬��������=�ܺ�-ż���͡� 
		printf("Case %d: %lld\n",++kase,ans);//printf("%Case %d: %lld\n",++kase,ans);ע�������ʽ���Ʒǳ����ࡣ 
	}
    return 0;
}

