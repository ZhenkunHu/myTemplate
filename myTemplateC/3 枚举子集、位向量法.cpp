#include<bits/stdc++.h>
using namespace std;

//位向量法
void print_subset(int n,int* A,int cur) {
    if(cur==n) {
        for(int i=0;i<cur;i++)
            if(A[i]) printf("%d ",i);//打印当前集合
        printf("\n");
        return;
    }
    A[cur]=1;//选第cur个元素
    print_subset(n,A,cur+1);
    A[cur]=0;//不选第cur个元素
    print_subset(n,A,cur+1);
}

int main() {
    int n,p[10];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&p[i]);
    sort(p,p+n);//排序，得到p的最小排列
    print_subset(n,p,0);
    return 0;
}
