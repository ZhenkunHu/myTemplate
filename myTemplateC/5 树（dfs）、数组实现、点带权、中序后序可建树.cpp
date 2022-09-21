#include<iostream>
#include<string>
#include<sstream>
#include<algorithm> 
using namespace std;

//��Ϊ�����ڵ��Ȩֵ������ͬ�Ҷ�����������ֱ����Ȩֵ��Ϊ����ţ���ζ������ʵ�֣� 
const int maxv=10000+10;
int in_order[maxv],post_order[maxv],lch[maxv],rch[maxv];
int n;

bool read_list(int* a)
{
	string line;
	if(!getline(cin,line)) return false;//getline()��ȡһ�� 
	stringstream ss(line);
	n=0;
	int x;
	while(ss>>x) a[n++]=x;//a[n++]=x;�򻯴��� 
	return n>0;//����n>0���򻯴��� 
} 

//��in_order[L1..R1]��post_order[L2..R2]����һ��������������
int build(int L1,int R1,int L2,int R2)//����һ��ջ֡��д�ݹ麯�� 
{
	if(L1>R1) return 0;//���� 
	int root=post_order[R2];//�����Ϊ����������һ��ֵ ��������ڵ���ֻ�Ǵ���ṹ�� 
	int p=L1;
	while(in_order[p]!=root) p++;//������������ҵ���
	int cnt=p-L1;//�������Ľ�����
	lch[root]=build(L1,p-1,L2,L2+cnt-1);//��Ϊ���㿪ʼ�����Լ�һ 
	rch[root]=build(p+1,R1,L2+cnt,R2-1);//������������������ʾ��� 
	return root; 
}
 
int best,best_sum;//ĿǰΪֹ�����Ž�Ͷ�Ӧ��Ȩ��

void dfs(int u,int sum)//������ȱ��� 
{
	sum+=u;
	if(!lch[u]&&!rch[u])//�����Ҷ�� 
	    if(sum<best_sum||(sum==best_sum&&u<best)) {best=u;best_sum=sum;}
	if(lch[u]) dfs(lch[u],sum);//����������ǿ� 
	if(rch[u]) dfs(rch[u],sum);//����������ǿ� 
}

int main()
{
    while(read_list(in_order))//һ���������� 
	{
		read_list(post_order);//������� 
		build(0,n-1,0,n-1);//���� 
		best_sum=1000000000;
		dfs(post_order[n-1],0);//�õ����Ž� 
		printf("%d\n",best);
    } 
    return 0;
}
