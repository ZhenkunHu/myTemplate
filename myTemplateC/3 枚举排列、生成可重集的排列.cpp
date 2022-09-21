#include<bits/stdc++.h>
using namespace std;

//生成可重集的排列
void print_permutation(int n,int *A,int *P,int cur) {
    if(cur==n) {//递归边界
        for(int i=0;i<n;i++) printf("%d ",A[i]);
        printf("\n");
    }
    else for(int i=0;i<n;i++) if(!i||P[i]!=P[i-1]) {//枚举的下标应不重复，又因为P数组已排好序
        int c1=0,c2=0;
        for(int j=0;j<cur;j++) if(A[j]==P[i]) c1++;
        for(int j=0;j<n;j++) if(P[i]==P[j]) c2++;
        if(c1<c2) {//递归调用的条件，取消了“禁止A数组中出现重复”的禁令。如果出现过但是没有选完
            A[cur]=P[i];
            print_permutation(n,A,P,cur+1);//递归调用
        }
    }
}

int main() {
    int a[10],p[3];
    for(int i=0;i<3;i++) {
        p[i]=1;
    }
    print_permutation(3,a,p,0);
    return 0;
}
