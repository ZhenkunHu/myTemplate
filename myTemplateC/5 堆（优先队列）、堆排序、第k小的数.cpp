#include <bits/stdc++.h>
using namespace std;

int maxHeap[105];
int maxHeap2[105];

void swap(int & a, int & b) {
    int t=a;
    a=b;
    b=t;
}

//建堆方式1 比方式2要快
void adjustDown(int a[], int k, int len) {
//向下调整以k为根的子树
//作为优先队列的出堆
    a[0]=a[k];//暂存，此时不用swap
    for(int i=k*2;i<=len;i*=2) {//i<=len，健壮性，避免死循环
        if(i<len&&a[i]<a[i+1]) i++;//取值较大的子节点的下标 i<len健壮性

        if(a[0]>a[i]) break;//a[0]暂存，每次是a[0]在和a[i]比较，所以可以优化swap
        else {
            a[k]=a[i];
            k=i;
        }
    }//for
    a[k]=a[0];//被筛选结点的值放入最终位置
}

void buildMaxHeap(int maxHeap[], int len) {
//从i=[n/2]~1，反复调整堆 复杂度O(n)
    for(int i=len/2;i>=1;i--) {
        adjustDown(maxHeap,i,len);
    }
}

//堆排序方式1 与堆排序方式2相似
void heapSort(int len) {
    //buildMaxHeap(maxHeap,n);
    for(int i=len;i>1;i--) {//n-1躺
        swap(maxHeap[1],maxHeap[i]);
        adjustDown(maxHeap,1,i-1);//i-1与i--区别
    }
}

//堆排序方式2，建立最小堆，一个一个deleteMin
int deleteMax(int n) {
//删除最大的元素 n=length
    int Max=maxHeap2[1];
    maxHeap2[1]=maxHeap2[n];
    adjustDown(maxHeap2,1,n-1);
    return Max;
}

//建堆方式2
void adjustUp(int a[], int k, int len) {
//向上调整k结点
//作为优先队列的入堆
    a[0]=a[k];
    for(int i=k/2;i>=1;i/=2) {//i>=1健壮性，当k=1时，i!=1，陷入死循环
        if(a[0]<a[i]) break;
        else {
            a[k]=a[i];
            k=i;
        }
    }//for
    a[k]=a[0];
}

void buildMaxHeap2(int maxHeap[], int len, int a[]) {
//插入一个元素到最后位置，然后向上调整
    int n=0;
    for(int i=1;i<=len;i++) {
        maxHeap[i]=a[n++];
        adjustUp(maxHeap,i,i);//注意形式参数 此时i=n
    }
}




int main() {

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&maxHeap[i]);
//建堆1
    buildMaxHeap(maxHeap,n);
    printf("%d\n",maxHeap[1]);
//建堆2
    int input[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14};//n=14
    buildMaxHeap2(maxHeap2,n,input);
    printf("%d\n",maxHeap2[1]);

//堆排序1
    heapSort(n);
    for(int i=1;i<=n;i++)
        printf("%d ",maxHeap[i]);

    printf("\n");

//堆排序2
    for(int i=n;i>=1;i--) {
        printf("%d ",deleteMax(i));
    }

    printf("\n");

//第k小的数，因为大顶堆，求manyNum中第5小的数 已经在堆里面的数据不能重复输入
    int maxHeap3[105];
    int manyNum[100000]={3,2,1,9,8,7,6,4,5,10,11,15,19,20,41};
    for(int i=0;i<5;i++)
        maxHeap3[i+1]=manyNum[i];
    buildMaxHeap(maxHeap3,5);

    for(int i=5;i<15;i++) {
        if(manyNum[i]<maxHeap3[1]) {
            maxHeap3[1]=manyNum[i];
            adjustDown(maxHeap3,1,5);
        }
    }
    printf("%d",maxHeap3[1]);

    return 0;
}

/*
input:
14
5 36 7 22 17 46 12 2 19 25 28 1 92 99
output:
建堆（优先队列）
99
14
堆排序结果
1 2 5 7 12 17 19 22 25 28 36 46 92 99
14 13 12 11 10 9 8 7 6 5 4 3 2 1

第k小的数(k=5)
int manyNum[100000]={3,2,1,9,8,7,6,4,5,10,11,15,19,20,41};
output:
5

数组作为形式参数就是指针，所以会改变maxHeap的值
封装函数时，可以不用全局变量，而是传入一个形式参数，这样可以控制变量不被改变。此外，传入形式参数还可以用const使变量不被改变
*/
