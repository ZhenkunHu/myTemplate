#include<iostream>
using namespace std;

//输入一个子天平，返回子天平是否平衡，参数W修改为子天平的总重量
bool solve(int &w)
{
	int w1,d1,w2,d2;
	bool b1=true,b2=true;
	cin>>w1>>d1>>w2>>d2;//因为递归输入，所以不必建树
	if(!w1) b1=solve(w1);
	if(!w2) b2=solve(w2);
	w=w1+w2;//之所以用第一个栈帧建造函数，是因为当前代码行总会回来的
	return b1&&b2&&(w1*d1==w2*d2);//在输入过程中就能完成判断
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
