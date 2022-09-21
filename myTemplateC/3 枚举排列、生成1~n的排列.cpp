#include<bits/stdc++.h>
using namespace std;

//枚举1~n的排列
void print_permutation(int n,int *A,int cur) {
    if(cur==n) {//递归边界
        for(int i=0;i<n;i++) printf("%d ",A[i]);
        printf("\n");
    }
    else for(int i=1;i<=n;i++) {//尝试在A[cur]中填各种整数i
        int ok=1;
        for(int j=0;j<cur;j++)
            if(A[j]==i) ok=0;//如果i已经在A[0]~A[cur-1]出现过，则不能再选
        if(ok) {
            A[cur]=i;
            print_permutation(n,A,cur+1);//递归调用
        }
    }
}

int main() {
    int a[5];
    for(int i=0;i<5;i++) {
        a[i]=i+1;
    }
    print_permutation(5,a,0);
    return 0;
}
