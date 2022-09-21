#include<stdio.h>

//����ṹ��
struct student {
    int num;
    float score;
    struct student *next;
};

//����һ��ֻ��ͷ���Ŀ�����
struct student *create_head() {
    struct student *head;
    head=(struct student*)malloc(sizeof(struct student));
    if(head==NULL) {//����ͷ���ʧ��
        printf("����ͷ���ʧ��!\n");
        return NULL;
    }
    head->next=NULL;
    return head;
}

//��sָ��Ľ���������,ʹ����������,������ͷ���
struct student *insert(struct student *head,struct student *s) {
    struct student *p=head;
    while(p->next!=NULL&&s->score>p->next->score)//�ر�ע��&&���Ҳ���д��,��s���,���p->next=NULL,p->next->score���г���
        p=p->next;
    if(p->next==NULL) {//s->score�������
        s->next=NULL; //p->next�͵���NULL����������������Ժϲ�
        p->next=s; //���ӽ��
    }
    else {
        s->next=p->next;
        p->next=s; //���ӽ��
    }
    return head;
}

//ɾ��������ֵΪnum�Ľ��,�������������ָ��
struct student *delete_note(struct student *head,int num_x) {
    struct student *p1=head->next,*p2=head;
    while(p1!=NULL&&p1->num!=num_x) {//�ر�ע��&&�����������ܵ���,���������p1ָ��NULLʱp1->num���г���
        p2=p1;
        p1=p1->next;
    }
    if(p1==NULL)//�ر�ע������if���ܵ���,���������p1ָ��NULLʱ,p1->num���г���
    printf("�Ҳ�������ɾ��Ҫ��Ľ��!!!\n");
    if(p1->num==num_x) {
        p2->next=p1->next;
        free(p1);
        printf("���ɾ���ɹ�!\n");
    }
    return head;
}

//���ҷ��������Ľ��,������ָ��ý���ָ��
struct student *search(struct student *head) {
    struct student *p=head->next;
    int num;
    printf("������Ҫ����ѧ����ѧ��:\n");
    scanf("%d",&num);
    while(p!=NULL&&p->num!=num) //�ر�ע������������д��,��д�����pָ��NULLʱp->num�Ҳ���,���г���
        p=p->next;
    if(p==NULL) {//�ر�ע������if���ܵ���,���������pָ��NULLʱp->num���г���
        printf("�Ҳ������������Ľ��!!!\n");
        return NULL;//���Ҳ������ؿ�ָ��
    }
    if(p->num==num) {
    printf("�ҵ����������Ľ��\n�ý��Ϊ%d\t%.1f\n",p->num,p->score);
    return p;	//���ز��ҵ���ָ��
    }
}

//���������
void print(struct student *head) {
    struct student *p;
    printf("��������: \n");
    p=head->next;
    while(p!=NULL) {
        printf("%d\t%.1f\n",p->num,p->score);
        p=p->next;
    }
}

//�ͷ�����
void free_list(struct student *head) {
    struct student *p=head ;
    printf("�ͷ�����:\n");
    while(p!=NULL) {
        head=head->next;
        free(p);
        p=head;
    }
    //free(p)//�����ͷ�ͷ�ڵ㣬������
    printf("�ͷ�����ɹ�!\n");
}

//����ͷ�������Ĳ��Գ���
void main() {
    struct student *p ,*head;
    char c;
    int num;
    float score;
    printf("ѧ���ɼ�����ϵͳ:\n");
    head=create_head();
    while(1) {
        printf("I:������(�Զ�����) D:ɾ����� S:���ҽ�� P:������� E:�ͷ������˳�����!\n");
        c=getch();//ע����getchar������
        switch(c) {
            case'I':
                printf("��ֱ�����Ҫ����ѧ����ѧ�źͷ���:\n");
                scanf("%d%f",&num,&score);
                p=(struct student*)malloc( sizeof(struct student));
                if(p==NULL)
                    printf("����ý��ʧ��!\n");
                p->num=num; p->score=score; //��p��ֵ
                insert(head,p);
                printf("����ɹ�!\n");
                break;
            case'D':
                printf("������Ҫɾ����ѧ����ѧ��:\n");
                scanf("%d",&num);
                delete_note(head,num);
                break;
            case'S':
                search(head);
                break;
            case'P':
                print(head);
                break;
            case'E':
                free_list(head);
        }
    }
    return 0;
}
