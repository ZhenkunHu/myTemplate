#include<iostream>
#include<cstring>
using namespace std;

const int maxn=100000+10;
int sum[maxn];

//���벢ͳ��һ������������ˮƽλ��Ϊp
void build(int p)
{
	int v;cin>>v;
	if(v==-1) return;//����
	sum[p]+=v;
	build(p-1);build(p+1);
}

//�߶��룬��ͳ��
bool init()
{
    int v;cin>>v;
	if(v==-1) return false;
	memset(sum,0,sizeof(sum));
	int pos=maxn/2;//������ˮƽλ��
	sum[pos]=v;
	build(pos-1);build(pos+1);
}

int main()
{
    int kase=0;
	while(init())
	{
	    int p=0;
	    while(sum[p]==0) p++;//������ߵ�Ҷ��
		cout<<"Case "<<++kase<<":\n"<<sum[p++];//������ĩ����ո�
		while(sum[p]!=0) cout<<" "<<sum[p++];
		cout<<"\n\n";
    }
    return 0;
}
