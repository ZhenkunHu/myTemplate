#include<bits/stdc++.h>
using namespace std;
int h[101];//存堆
int n;
//重载swap
void swap(int x,int y) {
    int t;
    t=h[x];h[x]=h[y];h[y]=t;
    return;
}
//向下调整
void siftdown(int i) {
    int t,flag=0;
    while(i*2<=n&&flag==0) {
        if(h[i]<h[i*2])
            t=i*2;
        else t=i;
        if(i*2+1<=n) {
            if(h[t]<h[i*2+1])
                t=i*2+1;
        }
        if(t!=i) {
            swap(t,i);
            i=t;
        }
        else flag=1;
    }
    return;
}
//建立堆
void creat() {
    int i;
    for(i=n/2;i>=1;i--)//从最后一个非叶节点到第一个节点依次进行向下调整
        siftdown(i);
    return;
}
//堆排序
void heapsort() {
    while(n>1) {
        swap(1,n);
        n--;
        siftdown(1);
    }
    return;
}

int main() {
    int i,num;
    scanf("%d",&num);
    for(i=1;i<=num;i++)
        scanf("%d",&h[i]);
    n=num;
    creat();
    heapsort();
    for(i=1;i<=num;i++)
        printf("%d ",h[i]);
    return 0;
}
//向上调整
void siftup(int i) {
    int flag=0;
    if(i==1) return;
    while(i!=1&&flag==0) {
        if(h[i]>h[i/2])
            swap(i,i/2);
        else flag=1;
        i=i/2;
    }
    return;
}
