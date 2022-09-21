#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn=1000+10;
char s[maxn];//保存读入结点 

struct Node{
	bool have_value;//是否被赋值过 
	int v;//结点值 
	Node *left,*right;
	Node():have_value(false),left(NULL),right(NULL){}//构造函数 
};

Node* root;//二叉树的根结点

bool failed;

Node* newnode() {return new Node();} //用new运算符申请内存，并执行构造函数。封装到newnode()中 
	
void addnode(int v,char* s){
	int n=strlen(s);
	Node* u=root;//从根结点开始往下走 
	for(int i=0;i<n;i++)
      if(s[i]=='L'){
      	if(u->left==NULL) u->left=newnode();//结点不存在，建立新结点 
		  u=u->left; //往左走 
      }else if(s[i]=='R'){
      	if(u->right==NULL) u->right=newnode();
      	u=u->right;
      }//忽略其他情况，即最后那个多余的右括号 
    if(u->have_value) failed=true;//已经赋过值，表明输入有误 
    u->v=v;
    u->have_value=true;//别忘记做标记 
}

bool bfs(vector<int>& ans){
	queue<Node*> q;
	ans.clear();
	q.push(root);// 初始时只有一个根节点 
	while(!q.empty()){
		Node* u=q.front();q.pop();
		if(!u->have_value) return false;//有结点没有被赋值过，表明输入有误 
		ans.push_back(u->v);//增加到输出序列尾部 
		if(u->left!=NULL) q.push(u->left);//把左结点（如果有）放进队列 
		if(u->right!=NULL) q.push(u->right);//把右结点（如果有）放进对列 
	}
	return true;//输入正确 
}
//释放二叉树
void remove_tree(Node* u){
	if(u==NULL) return;//提前判断比较稳妥 
	remove_tree(u->left);//递归释放左子树的空间 
	remove_tree(u->right);//递归释放右子树的空间 
	delete u; //调用u的析构函数，并释放u结点本身的内存 
}    

bool read_input(){
	failed=false;
	remove_tree(root); //注意内存泄漏，高水平素养。多组数据时用得上，释放上一组的内存 
	root=newnode();//创建根结点 
	for(;;){
		if(scanf("%s",s)!=1) return false;//整个输入结束 
		if(!strcmp(s,"()")) break;//读到结束标志，退出循环 
		int v;
		sscanf(&s[1],"%d",&v);//读入结点值 
		addnode(v,strchr(s,',')+1);//查找逗号，然后插入结点 
	}
	return true;
} 
int main()
{
	read_input();//建树 
	vector<int> Bfs;
	bfs(Bfs);//广度优先遍历 
	for(int i=0;i<Bfs.size();i++)
	    printf("%d ",Bfs[i]); 
	return 0;
} 

//动态化静态
Node* newnode1() {Node* u=&node[++cnt];u->left=u->right=NULL;u->have_value=false;return u;}

//内存池技术
queue<Node*> freenodes;
Node node[maxn];

void init()
{
	for(int i=0;i<maxn;i++)
	    freenodes.push(&node[i]);//初始化内存池 
}

Node* newnode2()
{
	Node* u=freenodes.front();
	u->left=u->right=NULL;u->have_value=false;//重新初始化该结点
	freenodes.pop();
	return u;
}

void deletenode(Node* u)//循环利用 
{
	freenodes.push(u);
}

//用数组实现
const int root=1;//结点编号：1.代替结构体；2.能实现简单遍历，如求和（因为结点顺序是结点的生成顺序） 
void newtree() {left[root]=right[root]=0;have_value[root]=false;cnt=root;}//代替remove_tree(root)和root=newnode() 
int newnode3() {int u=++cnt;left[u]=right[u]=0;have_value[root]=false;return u;} 
  





 
