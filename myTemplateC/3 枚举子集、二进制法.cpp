#include<bits/stdc++.h>
using namespace std;

//二进制法
void print_subset(int n,int s) {//打印{0，1，2，3，...，n-1}的子集s
    for(int i=0;i<n;i++)
        if(s&(1<<i)) printf("%d ",i);//非0值都为真
    printf("\n");
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<(1<<n);i++) //枚举各子集所对应的编码0，1，2，...，2^n-1
        print_subset(n,i);
    return 0;
}
