#include <stdio.h>
#include <iostream>
using namespace std;

int map[100][100],max_x,max_y;
//int book[100][100];

struct node {
    int x;
    int y;
    int step;
};

node queue[10010];
int front=0,rear=0;//队列与初始化

int h_next[2][2]={{0,1},{1,0}};//方向数组，只能向右、向下
int min_step=1000000000;

void bfs(int des_x,int des_y) {
    queue[rear].x=0;
    queue[rear].y=0;
    queue[rear].step=map[0][0];
    rear++;
    //book[0][0]=1;

    while(front<rear) {
        for(int i=0;i<2;i++) {
            int x=queue[front].x+h_next[i][0];
            int y=queue[front].y+h_next[i][1];

            if(x<0||x>=max_y||y<0||y>=max_y) continue;

            queue[rear].x=x;
            queue[rear].y=y;
            queue[rear].step=queue[front].step+map[x][y];
            rear++;
            //book[x][y]=1;

            if(x==des_x-1&&y==des_y-1) {
                if(min_step>queue[rear-1].step) min_step=queue[rear-1].step;
            }

        }//for
        front++;
    }
}


int main() {

    scanf("%d%d",&max_x,&max_y);
    for(int i=0;i<max_x;i++)
        for(int j=0;j<max_y;j++)
            scanf("%d",&map[i][j]);

    bfs(max_x,max_y);
    printf("%d\n",min_step);

	return 0;
}
/*

4 4
2 3 5 9
8 1 3 4
5 0 6 1
8 8 4 3
16
*/

