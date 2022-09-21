#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
#define maxd 100
#define BIG 10000
int r,c,n,d[maxd][maxd],d2[maxd][maxd],ans[maxd][maxd],cols[maxd];
    //r行c列的表格，n个操作指令，d存储表格中的标识数据，改变d
void copy(char type,int p,int q)                        //将新插入的或不删除的那组数copy到新表格中
{                                                      //p为要改变的表d中按顺序排列的数组，q为d2表中不删除的数组
    if(type=='R') {
        for(int i=1;i<=c;i++)d[p][i]=d2[q][i];
    }
    else {
        for(int i=1;i<=r;i++)d[i][p]=d2[i][q];
    }
}

void del(char type) {
    memcpy(d2,d,sizeof(d));
    int cnt=type=='R'?r:c,cnt2=0;         //如果是删除行即type=='R',就给cnt赋值为行数，否则为列数
    for(int i=1;i<=cnt;i++){
        if(!cols[i])copy(type,++cnt2,i);     //将不删除的数copy到新表格中
    }
    if(type=='R')r=cnt2;                  //删除后行列变少
    else c=cnt2;
}

void ins(char type) {
    memcpy(d2,d,sizeof(d));                     //d2用来储存原始数据来改变d
    int cnt=type=='R'?r:c,cnt2=0;
    for(int i=1;i<=cnt;i++){
        if(cols[i])copy(type,++cnt2,0);         //新插入数组的数组赋值为d[i][0]或d[0][j]
        copy(type,++cnt2,i);
    }
    if(type=='R')r=cnt2;
    else c=cnt2;
}

int main() {
   int r1,c1,r2,c2,q,kase=0;
   char cmd[10];
   memset(d,0,sizeof(d));
   while(scanf("%d%d%d",&r,&c,&n)==3&&r) {
       int r0=r,c0=c;
       for(int i=1;i<=r;i++)                                //把d[i][0]和d[0][j]留为新插入行和列的赋值
           for(int j=1;j<=c;j++) d[i][j]=i*BIG+j;            //给各个位置的元素赋一个特定的值，如 第一行第二列的值为10002
       while(n--) {
           scanf("%s",cmd);
           if(cmd[0]=='E') {                                 //交换
               scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
               int t=d[r1][c1];                             //交换两值即可
               d[r1][c1]=d[r2][c2];
               d[r2][c2]=t;
           }
           else {
               int a,x;
               scanf("%d",&a);
               memset(cols,0,sizeof(cols));
               for(int i=0;i<a;i++){
                   scanf("%d",&x);
                   cols[x]=1;                        //将要删除或者插入的(多个)第a行或第a列的数据赋值为1
               }
               if(cmd[0]=='D') del(cmd[1]);           //删除
               else ins(cmd[1]);                     //插入
           }
       }
       memset(ans,0,sizeof(ans));                    //用来存储变化
       for(int i=1;i<=r;i++)
           for(int j=1;j<=c;j++) {
               ans[d[i][j]/BIG][d[i][j]%BIG]=i*BIG+j;       //d与ans反着存储着，如d[1][1]=20001,则ans[2][1]=10001,原本2行1列的元素现在在1行1列
               printf("d[%d][%d]   %d\n",i,j,d[i][j]);
               printf("ans[%d][%d]   %d\n",d[i][j]/BIG,d[i][j]%BIG,i*BIG+j);
           }
           if(kase>0)printf("\n");
           printf("Spreadsheet #%d\n",++kase);
           scanf("%d",&q);
           while(q--) {
               scanf("%d%d",&r1,&c1);
               printf("Cell data in (%d,%d) ",r1,c1);
               if(ans[r1][c1]==0)printf("GONE\n");
               else printf("moved to (%d,%d)\n",ans[r1][c1]/BIG,ans[r1][c1]%BIG);
           }
   }
   //system("pause");
    return 0;
}


// 另一种思路是将所有的操作保存，然后对于每个查询重新执行每个操作，但不需要计算整个表格的变化，
//而只需要关注所查询的单元格的位置变化。
//这种方法对于题目给的规模，即好写，效率又高。
/*
#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
#define maxd 10000

struct Command{
    char c[5];
    int r1,c1,r2,c2;
    int a,x[20];
}cmd[maxd];
int r,c,n;

int simulate(int* r0,int* c0)
{
    for(int i=0;i<n;i++){                             //n次变换
        if(cmd[i].c[0]=='E'){
            if(cmd[i].r1==*r0&&cmd[i].c1==*c0){
                *r0=cmd[i].r2;
                *c0=cmd[i].c2;
            }
            else if(cmd[i].r2==*r0&&cmd[i].c2==*c0){
                *r0=cmd[i].r1;
                *c0=cmd[i].c1;
            }
        }
        else{
            int dr=0,dc=0;
            for(int j=0;j<cmd[i].a;j++){
                int x=cmd[i].x[j];                          //x[j]为变化的行数或列数
                if(cmd[i].c[0]=='I'){
                    if(cmd[i].c[1]=='R'&&x<=*r0)dr++;
                    if(cmd[i].c[1]=='C'&&x<=*c0)dc++;
                }
                else{
                    if(cmd[i].c[1]=='R'&&x==*r0)return 0;        //删除掉了
                    if(cmd[i].c[1]=='C'&&x==*c0)return 0;
                    if(cmd[i].c[1]=='R'&&x<*r0)dr--;
                    if(cmd[i].c[1]=='C'&&x<*c0)dc--;
                }
            }
            *r0+=dr;
            *c0+=dc;
        }
    }
    return 1;
}
int main()
{
   int r0,c0,q,kase=0;
   while(scanf("%d%d%d",&r,&c,&n)==3&&r){
       for(int i=0;i<n;i++){
           scanf("%s",cmd[i].c);
           if(cmd[i].c[0]=='E'){
               scanf("%d%d%d%d",&cmd[i].r1,&cmd[i].c1,&cmd[i].r2,&cmd[i].c2);
           }
           else{
               scanf("%d",&cmd[i].a);
               for(int j=0;j<cmd[i].a;j++)scanf("%d",&cmd[i].x[j]);
           }
       }
       if(kase>0)printf("\n");
       printf("Spreadsheet #%d\n",++kase);

       scanf("%d",&q);
       while(q--){
           scanf("%d%d",&r0,&c0);
           printf("Cell data in(%d,%d) ",r0,c0);
           if(!simulate(&r0,&c0))printf("GONE\n");
           else printf("moved to (%d,%d)\n",r0,c0);
       }
   }
 //  system("pause");
    return 0;
}
*/
