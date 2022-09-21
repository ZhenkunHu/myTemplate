#include<bits/stdc++.h>
using namespace std;

//增量构造法
void print_subset(int n,int* A,int cur) {
    for(int i=0;i<cur;i++) printf("%d ",A[i]);//打印当前集合
    printf("\n");
    int s=cur ? A[cur-1]+1:0;//确定当前元素的最小可能值
    for(int i=s;i<n;i++) {
        A[cur]=i;
        print_subset(n,A,cur+1);//递归构造子集
    }
}

int main() {
    int n,p[10];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&p[i]);
    sort(p,p+n);//排序，得到p的最小排列
    print_subset(n,p,0);
    return 0;
}
