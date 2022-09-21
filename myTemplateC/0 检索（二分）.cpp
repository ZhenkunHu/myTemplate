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
	for(int i=0;i<l;i++)//输入三个数组 
	cin>>a[i];
	for(int i=0;i<m;i++)
	cin>>b[i];
	for(int i=0;i<n;i++)
	cin>>c[i];
	int k=0;
	for(int i=0;i<l;i++)
	for(int j=0;j<m;j++)
	d[k++]=a[i]+b[j];//前两个数组两两相加得到新数组 
	sort(d,d+k);//从小到大排序 
	int s;
	cin>>s;
	cout<<"Case "<<kase++<<":"<<endl;//输出第几个测试实例 
	while(s--)
	{
		long long x;
		cin>>x;
		bool sign =false;//或者book 
		for(int i=0;i<n;i++)//第三个数组和新数组mid相加判断 
		{
		int l=0,r=k-1;
		while(l<=r)//二分 
		{
			int mid=(l+r)>>1;//位运算 
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
		if(sign)//实现多重break 
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

