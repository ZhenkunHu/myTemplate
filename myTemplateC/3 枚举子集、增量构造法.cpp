#include<bits/stdc++.h>
using namespace std;

//�������취
void print_subset(int n,int* A,int cur) {
    for(int i=0;i<cur;i++) printf("%d ",A[i]);//��ӡ��ǰ����
    printf("\n");
    int s=cur ? A[cur-1]+1:0;//ȷ����ǰԪ�ص���С����ֵ
    for(int i=s;i<n;i++) {
        A[cur]=i;
        print_subset(n,A,cur+1);//�ݹ鹹���Ӽ�
    }
}

int main() {
    int n,p[10];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&p[i]);
    sort(p,p+n);//���򣬵õ�p����С����
    print_subset(n,p,0);
    return 0;
}
