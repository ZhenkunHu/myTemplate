#include<cstring>//全面思想，手动模拟。更好的理解代码。 
#include<cstdio> 
const int maxn=100000+5;
int last,cur,next[maxn];//类似指针 。 
char s[maxn];//类似数据 。 

int main()
{
    while(scanf("%s",s+1)==1)
    {
    	int n=strlen(s+1);
    	last=cur=0;//0相当于NULL ，0指没有数据。 
    	next[0]=0;//相当与初始化第一个指针为NULL,即没有指向。 
    	
    	for(int i=1;i<=n;i++)
    	{
    		char ch=s[i];
    		if(ch=='[') cur=0;
    		else if(ch==']') cur=last;
    		else //代码合并能反映更基本的行为，说明行为具有一般性。（建立链表的过程其实就是插入结点的过程） 
    		{//插入操作要改变四个量！！！ 
    			next[i]=next[cur];// NULL的意义是让链表有尾，next[0]是头。 
    			next[cur]=i;//数组下标相当于存储地址！！！地址大小没有意义，只是作为一个地址。或者说地址把next和s绑到了一起。 
    			if(cur==last) last=i;//更新“最后一个字符”编号。 
    			cur=i;//后更新光标位置 。 
			}
		}
		for(int i=next[0];i!=0;i=next[i])//从头输到尾。 
		    printf("%c",s[i]);
		printf("\n");	
	}
    return 0;
}



