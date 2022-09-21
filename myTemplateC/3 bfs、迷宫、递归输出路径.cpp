#include <stdio.h>
#include <iostream>
using namespace std;

int map[51][51],max_x,max_y;
int book[51][51];

struct node {
    int x;
    int y;
    int father;
    int step;
};

node queue[2510];
int front=0,rear=0;//队列与初始化

int h_next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//方向数组，不能用next命名数组

void bfs(int des_x,int des_y) {
    //默认从0,0开始
    queue[rear].x=0;
    queue[rear].y=0;
    queue[rear].father=-1;
    queue[rear].step=0;
    rear++;
    book[0][0]=1;

    while(front<rear) {
        for(int i=0;i<4;i++) {
            int x=queue[front].x+h_next[i][0];
            int y=queue[front].y+h_next[i][1];

            if(x<0||x>=max_y||y<0||y>=max_y) continue;
            if(map[x][y]==0&&book[x][y]==0) {
                queue[rear].x=x;
                queue[rear].y=y;
                queue[rear].father=front;
                queue[rear].step=queue[front].step+1;
                rear++;
                book[x][y]=1;

                if(x==des_x&&y==des_y) return;//跳出多重循环，用flag=1;break;或者直接return
            }
        }//for
        front++;//顺序结构与循环结构不能交叉，front++放在了for循环外面
    }
}

void printPath(int i) {
    if(queue[i].father!=0) {
        printPath(queue[i].father);
    }
    printf("(%d,%d)->",queue[i].x,queue[i].y);
}

int main() {

    scanf("%d%d",&max_x,&max_y);
    for(int i=0;i<max_x;i++)
        for(int j=0;j<max_y;j++)
            scanf("%d",&map[i][j]);

    bfs(3,2);//目的地点3,2
    printf("%d\n",queue[rear-1].step);

    //输出路径1
    printPath(rear-1);
    printf("\n");
    //输出路径2
    int i=rear-1;
    while(queue[i].father!=0) {
        printf("(%d,%d)<-",queue[queue[i].father].x,queue[queue[i].father].y);//下标与地址一一对应，类比next *和静态链表
        i=queue[i].father;
    }


	return 0;
}

/*
5 4
0 0 1 0
0 0 0 0
0 0 1 0
0 1 0 0
0 0 0 1

7
*/
//链表的结点内部是连续的，数组是连续的，next[int]、next.int 数组、结构体，在机器世界有异曲同工之妙
//路径：深搜用栈，广搜用father
//两类问题：种子填充与迷宫问题
