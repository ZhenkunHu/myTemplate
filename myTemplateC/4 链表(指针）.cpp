#include<iostream>//指针和数组能达到相同的效果，能说明更基本的东西。（实现方法在物理层面上相同）
using namespace std;
struct Node
{
	int date;
	Node* next=NULL;
};

Node* creat(int n)
{
	Node *head,*p,*q;
	head=NULL;
	for(int i=1;i<=n;i++)
	{
		p=new Node;
		cin>>p->date;
		p->next=NULL;
		if(head==NULL) head=p;
		else q->next=p;
		q=p;
	}
    return head;
}

void print(Node* h)
{
	Node* p;
	p=h;
	while(p!=NULL)
	{
		cout<<p->date<<endl;
		p=p->next;
	}
}

Node* merge(Node* p1,Node* p2)
{

	Node *head,*p3;
	head=new Node;
	p3=head;
	if(p1->date>=p2->date)
    {
        head->date=p2->date;
        p2=p2->next;
    }
    else
    {
        head->date=p1->date;
        p1=p1->next;
    }

	for(;;)
    {
        if(p1==NULL)
        {
            p3->next=p2;
            break;
        }
        if(p2==NULL)
        {
            p3->next=p1;
            break;
        }
        p3->next=new Node;
        p3=p3->next;
        if(p1->date>p2->date)
        {

            p3->date=p2->date;
            p2=p2->next;
        }
        else
        {
            p3->date=p1->date;
            p1=p1->next;
        }
    }
    return head;
}


int main()
{
    Node *h1,*h2,*h3;
    h1=creat(7);
    h2=creat(9);
    print(h1);
    print(h2);
    h3=merge(h1,h2);
    print(h3);
}
