#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn=1000+10;
char s[maxn];//��������� 

struct Node{
	bool have_value;//�Ƿ񱻸�ֵ�� 
	int v;//���ֵ 
	Node *left,*right;
	Node():have_value(false),left(NULL),right(NULL){}//���캯�� 
};

Node* root;//�������ĸ����

bool failed;

Node* newnode() {return new Node();} //��new����������ڴ棬��ִ�й��캯������װ��newnode()�� 
	
void addnode(int v,char* s){
	int n=strlen(s);
	Node* u=root;//�Ӹ���㿪ʼ������ 
	for(int i=0;i<n;i++)
      if(s[i]=='L'){
      	if(u->left==NULL) u->left=newnode();//��㲻���ڣ������½�� 
		  u=u->left; //������ 
      }else if(s[i]=='R'){
      	if(u->right==NULL) u->right=newnode();
      	u=u->right;
      }//�������������������Ǹ������������ 
    if(u->have_value) failed=true;//�Ѿ�����ֵ�������������� 
    u->v=v;
    u->have_value=true;//����������� 
}

bool bfs(vector<int>& ans){
	queue<Node*> q;
	ans.clear();
	q.push(root);// ��ʼʱֻ��һ�����ڵ� 
	while(!q.empty()){
		Node* u=q.front();q.pop();
		if(!u->have_value) return false;//�н��û�б���ֵ���������������� 
		ans.push_back(u->v);//���ӵ��������β�� 
		if(u->left!=NULL) q.push(u->left);//�����㣨����У��Ž����� 
		if(u->right!=NULL) q.push(u->right);//���ҽ�㣨����У��Ž����� 
	}
	return true;//������ȷ 
}
//�ͷŶ�����
void remove_tree(Node* u){
	if(u==NULL) return;//��ǰ�жϱȽ����� 
	remove_tree(u->left);//�ݹ��ͷ��������Ŀռ� 
	remove_tree(u->right);//�ݹ��ͷ��������Ŀռ� 
	delete u; //����u���������������ͷ�u��㱾����ڴ� 
}    

bool read_input(){
	failed=false;
	remove_tree(root); //ע���ڴ�й©����ˮƽ��������������ʱ�õ��ϣ��ͷ���һ����ڴ� 
	root=newnode();//��������� 
	for(;;){
		if(scanf("%s",s)!=1) return false;//����������� 
		if(!strcmp(s,"()")) break;//����������־���˳�ѭ�� 
		int v;
		sscanf(&s[1],"%d",&v);//������ֵ 
		addnode(v,strchr(s,',')+1);//���Ҷ��ţ�Ȼ������� 
	}
	return true;
} 
int main()
{
	read_input();//���� 
	vector<int> Bfs;
	bfs(Bfs);//������ȱ��� 
	for(int i=0;i<Bfs.size();i++)
	    printf("%d ",Bfs[i]); 
	return 0;
} 

//��̬����̬
Node* newnode1() {Node* u=&node[++cnt];u->left=u->right=NULL;u->have_value=false;return u;}

//�ڴ�ؼ���
queue<Node*> freenodes;
Node node[maxn];

void init()
{
	for(int i=0;i<maxn;i++)
	    freenodes.push(&node[i]);//��ʼ���ڴ�� 
}

Node* newnode2()
{
	Node* u=freenodes.front();
	u->left=u->right=NULL;u->have_value=false;//���³�ʼ���ý��
	freenodes.pop();
	return u;
}

void deletenode(Node* u)//ѭ������ 
{
	freenodes.push(u);
}

//������ʵ��
const int root=1;//����ţ�1.����ṹ�壻2.��ʵ�ּ򵥱���������ͣ���Ϊ���˳���ǽ�������˳�� 
void newtree() {left[root]=right[root]=0;have_value[root]=false;cnt=root;}//����remove_tree(root)��root=newnode() 
int newnode3() {int u=++cnt;left[u]=right[u]=0;have_value[root]=false;return u;} 
  





 
