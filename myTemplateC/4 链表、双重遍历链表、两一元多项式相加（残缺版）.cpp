#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
struct  node {
    int  coef;
    int  exp;
    struct  node *next;
};

node *Createlist() {//创建一元多项式链表//把创建和插入合并了
    node *head,*middle,*s;//middle作为中间变量，s为新插入项
    int  coef, exp;
    head = (node *)malloc(sizeof(node));
    if(head==NULL) return NULL;
    head->next = NULL;
    middle = head;
    printf("请输入每一项的系数和指数:");
    scanf("%d%d",&coef,&exp);
    while (!((coef==0)&&(exp==0))) {//当系数和指数都为0时，多项式结束
        s = (node *)malloc (sizeof(node));
        if(s==NULL) return NULL;
        s->coef = coef;
        s->exp = exp;
        s->next = middle->next;
        middle->next = s;
        middle = s;
        printf("请继续输入：");
        scanf("%d%d",&coef,&exp);
    }
    return head;
}

//模仿顺序表遍历链表
node *Num;
node *ListAdd(node *listya,node *listyb) {
    Num=(node*)malloc(sizeof(node));
    if(Num==NULL) return NULL;
    Num->next=NULL;
    node *middle=Num;
    node *p=listya,*q=listyb;
    node *t;
    while(p->next!=NULL) {
        while(q->next!=NULL) {
            if(p->next->exp==q->next->exp) {
                //cout<<"p->next->exp"<<p->next->exp<<"q->next->exp"<<q->next->exp<<endl;
                t=(node*)malloc(sizeof(node));
                t->exp=p->next->exp;
                t->coef=p->next->coef+q->next->coef;
                //cout<<t->exp<<endl;
                t->next=middle->next;
                //if(t->next==NULL) cout<<"t->next==NULL"<<endl;
                middle->next=t;
                middle=t;
            }
            q=q->next;//相当于顺序表中++
        }
        p=p->next;
        q=listyb;//相当于顺序表中int i=0;
    }
    return Num;
}

int Print(node *h) {
    node *p = h->next;
    if(p) {
         printf("%d*x^%d",p->coef, p->exp);
         p=p->next;
    }
    while (p) {
        printf("+%d*x^%d",p->coef, p->exp);
        p = p->next;
    }
    printf("\n");
    return 1;
}

int main() {
    node *listya, *listyb;
    printf("输入结束标志位系数和指数同为0 \n");
    printf("请输入第一个一元多项式的系数和指数\n");
    listya = Createlist();
    printf("你输入的第一个一元多项式为:");
    Print(listya);
    printf("请输入第二个一元多项式的系数和指数\n");
    listyb = Createlist();
    printf("你输入的第二个一元多项式为:");
    Print(listyb);
    printf("两个一元多项式相加后的结果为:");
    ListAdd(listya,listyb);
    Print(Num);
    return 1;
}
