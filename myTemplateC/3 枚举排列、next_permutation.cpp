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
    sort(p,p+n);//���򣬵õ�p����С���У�һ��Ҫ������
    do {
        for(int i=0;i<n;i++) printf("%d ",p[i]);//�������p
        printf("\n");
    } while(next_permutation(p,p+n));//����һ������
    return 0;
}
