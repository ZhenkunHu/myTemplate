#include<cstring>//ȫ��˼�룬�ֶ�ģ�⡣���õ������롣 
#include<cstdio> 
const int maxn=100000+5;
int last,cur,next[maxn];//����ָ�� �� 
char s[maxn];//�������� �� 

int main()
{
    while(scanf("%s",s+1)==1)
    {
    	int n=strlen(s+1);
    	last=cur=0;//0�൱��NULL ��0ָû�����ݡ� 
    	next[0]=0;//�൱���ʼ����һ��ָ��ΪNULL,��û��ָ�� 
    	
    	for(int i=1;i<=n;i++)
    	{
    		char ch=s[i];
    		if(ch=='[') cur=0;
    		else if(ch==']') cur=last;
    		else //����ϲ��ܷ�ӳ����������Ϊ��˵����Ϊ����һ���ԡ�����������Ĺ�����ʵ���ǲ�����Ĺ��̣� 
    		{//�������Ҫ�ı��ĸ��������� 
    			next[i]=next[cur];// NULL����������������β��next[0]��ͷ�� 
    			next[cur]=i;//�����±��൱�ڴ洢��ַ��������ַ��Сû�����壬ֻ����Ϊһ����ַ������˵��ַ��next��s����һ�� 
    			if(cur==last) last=i;//���¡����һ���ַ�����š� 
    			cur=i;//����¹��λ�� �� 
			}
		}
		for(int i=next[0];i!=0;i=next[i])//��ͷ�䵽β�� 
		    printf("%c",s[i]);
		printf("\n");	
	}
    return 0;
}



