#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
struct  node {
    int  coef;
    int  exp;
    struct  node *next;
};

node *Createlist() {//����һԪ����ʽ����//�Ѵ����Ͳ���ϲ���
    node *head,*middle,*s;//middle��Ϊ�м������sΪ�²�����
    int  coef, exp;
    head = (node *)malloc(sizeof(node));
    if(head==NULL) return NULL;
    head->next = NULL;
    middle = head;
    printf("������ÿһ���ϵ����ָ��:");
    scanf("%d%d",&coef,&exp);
    while (!((coef==0)&&(exp==0))) {//��ϵ����ָ����Ϊ0ʱ������ʽ����
        s = (node *)malloc (sizeof(node));
        if(s==NULL) return NULL;
        s->coef = coef;
        s->exp = exp;
        s->next = middle->next;
        middle->next = s;
        middle = s;
        printf("��������룺");
        scanf("%d%d",&coef,&exp);
    }
    return head;
}

//ģ��˳����������
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
            q=q->next;//�൱��˳�����++
        }
        p=p->next;
        q=listyb;//�൱��˳�����int i=0;
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
    printf("���������־λϵ����ָ��ͬΪ0 \n");
    printf("�������һ��һԪ����ʽ��ϵ����ָ��\n");
    listya = Createlist();
    printf("������ĵ�һ��һԪ����ʽΪ:");
    Print(listya);
    printf("������ڶ���һԪ����ʽ��ϵ����ָ��\n");
    listyb = Createlist();
    printf("������ĵڶ���һԪ����ʽΪ:");
    Print(listyb);
    printf("����һԪ����ʽ��Ӻ�Ľ��Ϊ:");
    ListAdd(listya,listyb);
    Print(Num);
    return 1;
}
