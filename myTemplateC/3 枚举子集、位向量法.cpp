#include<bits/stdc++.h>
using namespace std;

//λ������
void print_subset(int n,int* A,int cur) {
    if(cur==n) {
        for(int i=0;i<cur;i++)
            if(A[i]) printf("%d ",i);//��ӡ��ǰ����
        printf("\n");
        return;
    }
    A[cur]=1;//ѡ��cur��Ԫ��
    print_subset(n,A,cur+1);
    A[cur]=0;//��ѡ��cur��Ԫ��
    print_subset(n,A,cur+1);
}

int main() {
    int n,p[10];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&p[i]);
    sort(p,p+n);//���򣬵õ�p����С����
    print_subset(n,p,0);
    return 0;
}
