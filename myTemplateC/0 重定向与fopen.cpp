//�ض���
#define LOCAL//��������ָ��
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
    std::cout<<min<<" "<<max<<" "<<(double)s/n<<std::endl;//�ض���һ�����������//std����һ���࣬�����˺ܶ�ָ�//ʵ����std�������ռ�
    return 0;
}

//fopen()
/*
#include<iostream>
#define INF 1000000000
int main()
{
	FILE *fin,*fout;
	fin=fopen("data.in","rb");//��̬�ģ������Զ����롣
	fout=fopen("data.out","wb");
	int x,n=0,min=INF,max=-INF,s=0;//1000000000ʵ������С�������
	while(fscanf(fin,"%d",&x)==1)//���ʹ�ã�
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
