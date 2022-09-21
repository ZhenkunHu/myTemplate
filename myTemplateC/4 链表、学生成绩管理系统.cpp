#include<stdio.h>

//定义结构体
struct student {
    int num;
    float score;
    struct student *next;
};

//创建一个只有头结点的空链表
struct student *create_head() {
    struct student *head;
    head=(struct student*)malloc(sizeof(struct student));
    if(head==NULL) {//申请头结点失败
        printf("申请头结点失败!\n");
        return NULL;
    }
    head->next=NULL;
    return head;
}

//将s指向的结点插入链表,使链表保持升序,并返回头结点
struct student *insert(struct student *head,struct student *s) {
    struct student *p=head;
    while(p->next!=NULL&&s->score>p->next->score)//特别注意&&左右不能写反,若s最大,最后p->next=NULL,p->next->score运行出错
        p=p->next;
    if(p->next==NULL) {//s->score最大的情况
        s->next=NULL; //p->next就等于NULL，所以两种情况可以合并
        p->next=s; //连接结点
    }
    else {
        s->next=p->next;
        p->next=s; //连接结点
    }
    return head;
}

//删除链表中值为num的结点,并返回链表的首指针
struct student *delete_note(struct student *head,int num_x) {
    struct student *p1=head->next,*p2=head;
    while(p1!=NULL&&p1->num!=num_x) {//特别注意&&左右条件不能调换,若调换如果p1指向NULL时p1->num运行出错
        p2=p1;
        p1=p1->next;
    }
    if(p1==NULL)//特别注意两个if不能调换,若调换如果p1指向NULL时,p1->num运行出错
    printf("找不到符合删除要求的结点!!!\n");
    if(p1->num==num_x) {
        p2->next=p1->next;
        free(p1);
        printf("结点删除成功!\n");
    }
    return head;
}

//查找符合条件的结点,并返回指向该结点的指针
struct student *search(struct student *head) {
    struct student *p=head->next;
    int num;
    printf("请输入要查找学生的学号:\n");
    scanf("%d",&num);
    while(p!=NULL&&p->num!=num) //特别注意两条件不能写反,若写反最后p指向NULL时p->num找不到,运行出错
        p=p->next;
    if(p==NULL) {//特别注意两个if不能调换,若调换最后p指向NULL时p->num运行出错
        printf("找不到符合条件的结点!!!\n");
        return NULL;//查找不到返回空指针
    }
    if(p->num==num) {
    printf("找到符合条件的结点\n该结点为%d\t%.1f\n",p->num,p->score);
    return p;	//返回查找到的指针
    }
}

//对链表遍历
void print(struct student *head) {
    struct student *p;
    printf("链表如下: \n");
    p=head->next;
    while(p!=NULL) {
        printf("%d\t%.1f\n",p->num,p->score);
        p=p->next;
    }
}

//释放链表
void free_list(struct student *head) {
    struct student *p=head ;
    printf("释放链表:\n");
    while(p!=NULL) {
        head=head->next;
        free(p);
        p=head;
    }
    //free(p)//不用释放头节点，还能用
    printf("释放链表成功!\n");
}

//含有头结点链表的测试程序
void main() {
    struct student *p ,*head;
    char c;
    int num;
    float score;
    printf("学生成绩管理系统:\n");
    head=create_head();
    while(1) {
        printf("I:插入结点(自动升序) D:删除结点 S:查找结点 P:输出链表 E:释放链表并退出程序!\n");
        c=getch();//注意与getchar的区别
        switch(c) {
            case'I':
                printf("请分别输入要插入学生的学号和分数:\n");
                scanf("%d%f",&num,&score);
                p=(struct student*)malloc( sizeof(struct student));
                if(p==NULL)
                    printf("申请该结点失败!\n");
                p->num=num; p->score=score; //给p赋值
                insert(head,p);
                printf("插入成功!\n");
                break;
            case'D':
                printf("请输入要删除的学生的学号:\n");
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
