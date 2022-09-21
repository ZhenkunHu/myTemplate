#include<iostream>
#include<string>
#include<sstream>
#include<algorithm> 
using namespace std;

//因为各个节点的权值各不相同且都是正整数，直接用权值作为结点编号（意味着数组实现） 
const int maxv=10000+10;
int in_order[maxv],post_order[maxv],lch[maxv],rch[maxv];
int n;

bool read_list(int* a)
{
	string line;
	if(!getline(cin,line)) return false;//getline()读取一行 
	stringstream ss(line);
	n=0;
	int x;
	while(ss>>x) a[n++]=x;//a[n++]=x;简化代码 
	return n>0;//返回n>0，简化代码 
} 

//把in_order[L1..R1]和post_order[L2..R2]建成一棵树，返回树根
int build(int L1,int R1,int L2,int R2)//按第一个栈帧编写递归函数 
{
	if(L1>R1) return 0;//空树 
	int root=post_order[R2];//根结点为后序遍历最后一个值 。在这里，节点编号只是代替结构体 
	int p=L1;
	while(in_order[p]!=root) p++;//在中序遍历中找到根
	int cnt=p-L1;//左子树的结点个数
	lch[root]=build(L1,p-1,L2,L2+cnt-1);//因为从零开始，所以减一 
	rch[root]=build(p+1,R1,L2+cnt,R2-1);//加左子树结点个数来表示编号 
	return root; 
}
 
int best,best_sum;//目前为止的最优解和对应的权和

void dfs(int u,int sum)//深度优先遍历 
{
	sum+=u;
	if(!lch[u]&&!rch[u])//如果有叶子 
	    if(sum<best_sum||(sum==best_sum&&u<best)) {best=u;best_sum=sum;}
	if(lch[u]) dfs(lch[u],sum);//如果左子树非空 
	if(rch[u]) dfs(rch[u],sum);//如果右子树非空 
}

int main()
{
    while(read_list(in_order))//一旦输入中序 
	{
		read_list(post_order);//输入后序 
		build(0,n-1,0,n-1);//建树 
		best_sum=1000000000;
		dfs(post_order[n-1],0);//得到最优解 
		printf("%d\n",best);
    } 
    return 0;
}
