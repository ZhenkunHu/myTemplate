#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	long long l,m,n,kase=1;
	while(cin>>l>>m>>n)
	{
	long long a[501],b[501],c[501],d[250002];
	for(int i=0;i<l;i++)//������������ 
	cin>>a[i];
	for(int i=0;i<m;i++)
	cin>>b[i];
	for(int i=0;i<n;i++)
	cin>>c[i];
	int k=0;
	for(int i=0;i<l;i++)
	for(int j=0;j<m;j++)
	d[k++]=a[i]+b[j];//ǰ��������������ӵõ������� 
	sort(d,d+k);//��С�������� 
	int s;
	cin>>s;
	cout<<"Case "<<kase++<<":"<<endl;//����ڼ�������ʵ�� 
	while(s--)
	{
		long long x;
		cin>>x;
		bool sign =false;//����book 
		for(int i=0;i<n;i++)//�����������������mid����ж� 
		{
		int l=0,r=k-1;
		while(l<=r)//���� 
		{
			int mid=(l+r)>>1;//λ���� 
			if(d[mid]+c[i]==x)
			{
				sign=true;
				break;
			}
			else if(d[mid]+c[i]<x)
			{
				l=mid+1;
			}
			else
			r=mid-1;
		}	
		if(sign)//ʵ�ֶ���break 
		break;
		}
		if(sign)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}	
	}
	return 0;

}

