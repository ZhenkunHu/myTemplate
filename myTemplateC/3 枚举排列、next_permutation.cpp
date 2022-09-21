#include<bits/stdc++.h>
using namespace std;

/*
int cmp(char a, char b) {
    return a<b;
}
*/

int main() {
    int n,p[10];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&p[i]);
    sort(p,p+n);//排序，得到p的最小排列，一定要先排序
    do {
        for(int i=0;i<n;i++) printf("%d ",p[i]);//输出排列p
        printf("\n");
    } while(next_permutation(p,p+n));//求下一个排列
    return 0;
}
