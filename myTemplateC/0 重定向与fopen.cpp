//重定向
#define LOCAL//条件编译指令
#include<iostream>
#define INF 1000000000
int main()
{
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    int x,n=0,min=INF,max=-INF,s=0;
    while(scanf("%d",&x)==1)
    {
    	s+=x;
    	if(x<min) min=x;
    	if(x>max) max=x;
    	n++;
    }
    std::cout<<min<<" "<<max<<" "<<(double)s/n<<std::endl;//重定向：一切输入输出。//std类似一个类，声明了很多指令。//实际上std是命名空间
    return 0;
}

//fopen()
/*
#include<iostream>
#define INF 1000000000
int main()
{
	FILE *fin,*fout;
	fin=fopen("data.in","rb");//静态的，类似自动导入。
	fout=fopen("data.out","wb");
	int x,n=0,min=INF,max=-INF,s=0;//1000000000实现无穷小和无穷大。
	while(fscanf(fin,"%d",&x)==1)//如何使用？
	{
		s=+x;
		if(x<min) min=x;
		if(x>max) max=x;
		n++;
	}
	fprintf(fout,"%d %d %.3f\n",min,max,(double)s/n);
	fclose(fin);
	fclose(fout);
	return 0;
}
*/
