#include<iostream>
using namespace std;

//����һ������ƽ����������ƽ�Ƿ�ƽ�⣬����W�޸�Ϊ����ƽ��������
bool solve(int &w)
{
	int w1,d1,w2,d2;
	bool b1=true,b2=true;
	cin>>w1>>d1>>w2>>d2;//��Ϊ�ݹ����룬���Բ��ؽ���
	if(!w1) b1=solve(w1);
	if(!w2) b2=solve(w2);
	w=w1+w2;//֮�����õ�һ��ջ֡���캯��������Ϊ��ǰ�������ܻ������
	return b1&&b2&&(w1*d1==w2*d2);//����������о�������ж�
}

int main()
{
    int t,w;
	cin>>t;
	while(t--)
	{
	    if(solve(w)) cout<<"YES\n";else cout<<"NO\n";
		if(t) cout<<"\n";
    }
    return 0;
}
